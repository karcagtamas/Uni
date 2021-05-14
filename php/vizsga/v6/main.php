<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

spl_autoload_register(function ($name) {
    require_once "$name.php";
});

$db = new Database("localhost", "karcagtamas", "Tomi42457", "hallgatok");

if (isset($_POST['id']) && isset($_POST['rate'])) {
    $db->addRate(intval($_POST['id']), intval($_POST['rate']));
}

if (isset($_GET["movieNo"]) && $_GET["movieNo"] !== "") {
    $movies = $db->getMovies(intval($_GET["movieNo"]));
}
else {
    $movies = $db->getMovies();
}

?>
<!DOCTYPE html>
<html>
<head></head>
<body>
<h1>Mozfilmek minősítése</h1>
<a href="movie.php">Új felvétel</a>
<br>
<br>
<div>
    <?php
        foreach($movies as $movie) {
            $movie->displayCard($db);
        }
        $export = new ExportHandler($db);
        $path = $export->createJson();
        echo "<a href='{$path}'>Download export</a>";
    ?>

    <form method="get" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        <label>Darabszám: <input name="movieNo" type="number" min="0" /></label>
        <br> <button>Frissít</button>
    </form>
</div>
</body>
</html>
