<!DOCTYPE html>
<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
session_start();

$causedError = false;

if (empty($_SESSION["table"])) {
    $_SESSION["table"] = [];
}

function getMinVal($val, $type): int
{
    return $val[$type]["hours"] * 60 + $val[$type]["min"];
}

function isBlocked($base, $check): bool
{
    $baseStart = getMinVal($base, "start");
    $baseEnd = getMinVal($base, "end");
    $checkStart = getMinVal($check, "start");
    $checkEnd = getMinVal($check, "end");
    return $baseStart <= $checkStart && $baseEnd >= $checkStart || $baseStart <= $checkEnd && $baseEnd >= $checkEnd;
}

function optChange(&$val): void {
    if (getMinVal($val, "start") > getMinVal($val, "end")) {
        $cp = $val["start"];
        $val["start"] = $val["end"];
        $val["end"] = $cp;
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && !empty($_POST['name']) && !empty($_POST['start'] && !empty($_POST['end']))) {
    $start = explode(":", $_POST["start"]);
    $end = explode(":", $_POST["end"]);
    $array = ["name" => $_POST['name'], "start" => ["hours" => intval($start[0]), "min" => intval($start[1])], "end" => ["hours" => intval($end[0]), "min" => intval($end[1])]];
    optChange($array);

    foreach ($_SESSION["table"] as $i) {
        if (isBlocked($i, $array)) {
            $causedError = true;
            break;
        }
    }
    if (!$causedError) {
        array_push($_SESSION["table"], $array);
    }
}

function cellIsUsed($hour, $min): bool
{
    foreach ($_SESSION["table"] as $i) {
        $start = getMinVal($i, "start");
        $end = getMinVal($i, "end");
        $minVal = $hour * 60 + $min;

        if ($minVal >= $start && $minVal <= $end) {
            return true;
        }
    }

    return false;
}

?>

<html>
<head>
    <style>
        td, th {
            width: 20px;
            height: 20px;
        }

        .green {
            background-color: green;
        }

        .red {
            background-color: red;
        }
    </style>
</head>
<body>
<?php if ($causedError) echo "<div>" . "Error" . "</div>"; ?>
<ul>
    <?php
    foreach ($_SESSION["table"] as $i) {
        echo "<li>";

        echo $i["name"] . " - " . $i["start"]["hours"] . ":" . $i["start"]["min"] . " - " . $i["end"]["hours"] . ":" . $i["end"]["min"];

        echo "</li>";
    }
    ?>
</ul>
<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <label>
        Name: <input type="text" name="name"/>
    </label>
    <label>
        Start: <input type="time" name="start"/>
    </label>
    <label>
        End: <input type="time" name="end"/>
    </label>
    <br/>
    <button type="submit">Submit</button>
</form>
<table>
    <?php
    for ($i = -1; $i <= 23; $i++) {
        echo "<tr>";
        for ($j = -1; $j <= 59; $j++) {
            if ($i == -1 && $j == -1) {
                echo "<th></th>";
            } else if ($i == -1) {
                echo "<th>" . $j . "</th>";
            } else if ($j == -1) {
                echo "<th>" . $i . "</th>";
            } else {
                $color = cellIsUsed($i, $j) ? "red" : "green";
                echo "<td class=\"" . $color . "\"></td>";
            }
        }
        echo "</tr>";
    }
    ?>
</table>
</body>
</html>

