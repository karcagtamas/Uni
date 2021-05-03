<?php
namespace v1;
session_start();
require_once "Table.php";
require_once "Cell.php";

if (!empty($_POST["size"])) {
    $_SESSION["size"] = $_POST["size"];
}

if (empty($_SESSION["size"])) {
    $_SESSION["size"] = 8;
}

$table = new Table($_SESSION["size"]);
$checkTable = false;
if(!empty($_POST)) {
    $checkTable = true;
    $array = [];
    foreach ($_POST as $key => $el) {
        if (str_contains($key, "_q")) {

            $parts = explode("_", $key);
            array_push($array, ["x" => $parts[0], "y" => $parts[1]]);
        }
    }
    $table->setQueens($array);
}

?>

<!DOCTYPE html>
<html>
<head>
    <style>
        .graph {
            border-collapse: collapse;
        }
        .graph th, .graph td, img {
            width: 50px !important;
            height: 50px !important;
        }

        .graph th {
            background-color: gray;
        }

        .graph td {
            background-color: white;
        }

        .graph .ch:nth-child(even) td:nth-child(odd) {
            background-color: black;
        }

        .graph .ch:nth-child(odd) td:nth-child(even) {
            background-color: black;
        }

    </style>
</head>

<body>
    <form action="<?php echo $_SERVER["PHP_SELF"]; ?>" method="post">
        <div><?php echo $table->generate(); ?></div>

        <button type="submit">Ellenőriz</button>
    </form>
    <div>
        <?php
        if ($table->isCorrect()) {
            echo $table->generate(1, false);
            echo $table->generate(2, false);
            echo $table->generate(3, false);
        }
        ?>
    </div>
    <div>
        <?php
        if ($table->isCorrect()) {
            echo $table->displayGraphic();
        }
        ?>
    </div>
    <span>
        <?php
            if ($checkTable && $table->isCorrect()) {
                echo "Correct";
            }
        ?>
    </span>
    <a href="./size.php">Vissza</a>
</body>
</html>
