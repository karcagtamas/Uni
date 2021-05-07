<?php
    require_once "Database.php";
    session_start();

    if (!empty($_POST["city"])) {
        if ($_POST["city"] == -1) {
            if (!empty($_POST["del"])) {
                foreach($_POST["del"] as $id) {
                    $item = array_search($id, $_SESSION["cities"]);
                    array_splice($_SESSION["cities"], $item, 1);
                }
            }
        }
        else if ($_POST["city"] == -2) {
            if (!empty($_POST["del"]) && count($_POST["del"]) == 2) {
                $item1 = array_search($_POST["del"][0], $_SESSION["cities"]);
                $item2 = array_search($_POST["del"][1], $_SESSION["cities"]);
                $cs = $_SESSION["cities"][$item1];
                $_SESSION["cities"][$item1] = $_SESSION["cities"][$item2];
                $_SESSION["cities"][$item2] = $cs;
            }
        }
        else {
            if (!empty($_SESSION["cities"])) {
                $_SESSION["cities"][] = $_POST["city"];
            }
            else {
                $_SESSION["cities"] = [$_POST["city"]];
            }
        }
    }

    if (!empty($_GET["reset"])) {
        $_SESSION["cities"] = [];
    }

    $db = new Database("localhost", "karcagtamas", "Tomi42457", "hallgatok");

    $cities = $db->getCities();
?>

<!DOCTYPE html>
<html>
<head></head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <select name="city">
            <?php
            echo "<option value='-1'>TÖRLÉS</option>";
            echo "<option value='-2'>CSERE</option>";
            foreach ($cities as $city) {
                if (!in_array($city["id"], $_SESSION["cities"])) {
                    echo "<option value='{$city['id']}'>{$city['nev']}</option>";
                }
            }
            ?>
        </select> <br/>
        <ol>
            <?php
            foreach ($_SESSION["cities"] as $id) {
                $city = $cities[array_search($id, array_column($cities, 'id'))];
                echo "<li><input type='checkbox' value='{$city['id']}' name='del[]' />{$city['nev']}</li>";
            }
            ?>
        </ol>
        <button type="submit">Tovább</button>
    </form>


    <button onclick="toCircle()">Kör megtekintése</button>
</body>
</html>

<script>
    function toCircle() {
        window.location = "circle.php";
    }
</script>

