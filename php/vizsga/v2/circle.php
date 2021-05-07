<?php
require_once "Database.php";
session_start();

$db = new Database("localhost", "karcagtamas", "Tomi42457", "hallgatok");

$cities = $db->getCities();

$sum = 0;
?>

<!DOCTYPE html>
<html>
<head></head>
<body>
<?php
    for ($i = 0; $i < count($_SESSION["cities"]); $i++) {
        $v1 = $_SESSION["cities"][$i];
        $v2 = $_SESSION["cities"][$i == (count($_SESSION["cities"]) - 1) ? 0 : ($i + 1)];

        $length = $db->getLengthBetweenTwoCity($v1, $v2);
        $sum += $length;

        $city1 = $cities[array_search($v1, array_column($cities, 'id'))];
        $city2 = $cities[array_search($v2, array_column($cities, 'id'))];

        echo "<div>{$city1["nev"]} -> {$city2["nev"]}: {$length} km</div>";
    }

    echo "<div>Összes megtett út: {$sum} km</div>";
?>
<button onclick="reset()">Újrakezd</button>
</body>
</html>

<script>
    function reset() {
        window.location = "main.php?reset=1";
    }
</script>

