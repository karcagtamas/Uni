<!DOCTYPE>
<?php
    $meccsek = [];
    $fogadasok = [];
    $odds = 1;
    $f = fopen("meccs.txt", "r") or die("File could not open");

    while(!feof($f)) {
        $t = explode(" ", fgets($f));
        $row = [
                "hazai" => $t[0],
                "vendeg" => $t[1],
                "haza_gyozelem" => floatval($t[2]),
                "dontetlen" => floatval($t[3]),
                "vendeg_gyozelem" => floatval($t[4])
        ];
        array_push($meccsek, $row);
    }

    fclose($f);

    $f = fopen("fogadasok.txt", "r") or die("File could not open");

    while(!feof($f)) {
        $t = explode(" ", fgets($f));



        if ($t[0] == 0) {
            break;
        }

        $row = [
            "nr" => intval($t[0]) - 1,
            "tip" => $t[1]
        ];

        $val = 1;
        switch (trim($row["tip"])) {
            case "H":
                $val = $meccsek[$row["nr"]]["haza_gyozelem"];
                break;
            case "D":
                $val = $meccsek[$row["nr"]]["dontetlen"];
                break;
            case "V":
                $val = $meccsek[$row["nr"]]["vendeg_gyozelem"];
                break;
            default:
                $val = 1;
        }

        $odds *= $val;

        array_push($fogadasok, $row);
    }

    fclose($f);
?>
<html>
<head></head>
<body>
Kivalasztott fogadasok: <br>
<?php
    foreach ($fogadasok as $val) {
        echo $meccsek[$val["nr"]]["hazai"]." - ".$meccsek[$val["nr"]]["vendeg"].": ".$val["tip"]."<br>";
    }
?>

A kombinalt odds: <?php echo $odds; ?>

</body>
</html>