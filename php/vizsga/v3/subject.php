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
$subject = $db->getSubject($_GET["subject"]);
if ($subject) {
    $display->displaySubject($subject);
    $prevs = $db->getAllPrevs($_GET["subject"]);
    $display->displayPrevTable($prevs);
}
$display->displayBackToHomeButton();
?>
</body>
</html>


