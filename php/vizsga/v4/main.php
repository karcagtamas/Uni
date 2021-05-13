<?php

declare(strict_types = 1);

spl_autoload_register(function ($name) {
    require_once "$name.php";
});

$started = !empty($_POST['alive']);

if ($started) {
    $game = new Game(20, $_POST["alive"]);
}
else {
    $game = new Game(20);
}


?>

<!DOCTYPE html>
<html>
<head></head>
<body>
<?php
if ($started) {
    $game->start();
}
else {
    $game->init();
}

?>
</body>
</html>
