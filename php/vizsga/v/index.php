<?php
ini_set('display_errors', 1);
spl_autoload_register(function ($name) {
    require_once "$name.php";
});

?>

<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>
<body>
<?php
$table = new Table();

$table->displayUserSelect();
?>
</body>
</html>

