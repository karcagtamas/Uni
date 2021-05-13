<?php

declare(strict_types = 1);

spl_autoload_register(function ($name) {
    require_once "$name.php";
});

session_start();

if (empty($_SESSION['table'])) {
    $_SESSION['table'] = serialize(new Table(10, 10));
}

$table = unserialize($_SESSION['table']);

if (isset($_GET["cellx"]) && isset($_GET["celly"])) {
    $table->hitField(intval($_GET["cellx"]), intval($_GET["celly"]));
    $_SESSION['table'] = serialize($table);
}

if (!empty($_GET["reset"]) && $_GET["reset"] == 1) {
    $table = new Table(10, 10);
    $_SESSION['table'] = serialize($table);
}
?>
<!DOCTYPE html>
<html>
<head>
    <style>
        button {
            height: 30px;
            width: 30px;
        }

        .panel {
            display: flex;
        }

        .result {
            padding: 1rem;
        }
    </style>
</head>
<body>
<div class="panel">
    <div>
        <?php
        $table->display();
        ?>
    </div>
    <div class="result">
        <?php
            echo "Lövések: {$table->getHits()}";
        ?>
    </div>
</div>


</body>
</html>
