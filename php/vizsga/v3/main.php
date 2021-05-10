<?php
    spl_autoload_register(function ($name) {
        require_once "$name.php";
    });

    $db = new Database("localhost", "karcagtamas", "Tomi42457", "hallgatok");
    $display = new Display();
?>
<!DOCTYPE html>
<html>
<head></head>
<body>
<?php
    $subjects = $db->getSubjects();
    $display->displayForm($subjects);
    $display->displayHr();
    $display->displayPeriodSelectorForm($subjects);
    if (!empty($_POST["subjects"]) && isset($_POST["period"])) {
        $next = [];
        $period = intval($_POST["period"]);

        foreach ($subjects as $subject) {
            if ($subject->getAf() % 2 == $period) {
                array_push($next, $subject);
            }
        }
        echo "<hr> Érdemes felvenni: <br>";

        foreach($next as $subject) {
            echo "<div>{$subject->getName()}</div>";
        }
    }
?>
</body>
</html>


