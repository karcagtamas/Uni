<?php
    ini_set('display_errors', 1);
    spl_autoload_register(function ($name) {
        require_once "$name.php";
    });

    session_start();

    if (isset($_POST["color"]) && isset($_POST["id"])) {
        $db = new Database();
        $lamp = $db->getLamp(intval($_POST["id"]));
        if ($lamp == null) {
            die("Invalid lamp");
        }
        $lamp->setHexColor($_POST["color"]);
        $db->updateLamp($lamp);
    }

    if (isset($_POST["user"])) {
        $_SESSION["user"] = $_POST["user"];
    }

    $exporter = new JsonExport();
    $exportPath = $exporter->exportLamps();
?>
<!DOCTYPE html>
<html>
<head>
<title></title>
</head>
<body>
<?php
    $table = new Table();

    if (isset($_SESSION["user"])) {
        $table->displayLampTable($_SESSION["user"]);
    }
    else {
        $table->displayLampTable();
    }

    echo "<br>";
    echo "<a href='$exportPath'>Download..</a>";

    $table->displayAdminTable();

?>
</body>
</html>
