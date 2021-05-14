<?php
spl_autoload_register(function ($name) {
    require_once "$name.php";
});

if (isset($_POST["title"]) && isset($_FILES["image"]) && isset($_POST["description"])) {
    $db = new Database("localhost", "karcagtamas", "Tomi42457", "hallgatok");
    $imageHandler = new ImageHandler();

    $imageHandler->saveImage($_FILES["image"]["name"], $_FILES["image"]["tmp_name"]);

    $db->addMovie($_POST["title"], $_FILES["image"]["name"], $_POST["description"]);
}

?>
<!DOCTYPE html>
<html>
<head></head>
<body>
<h1>Mozfilmek létrehozása</h1>
<br>
<div>
    <form enctype="multipart/form-data" method="post" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
        <label>
            Film címe:
            <input name="title" required />
        </label> <br>
        <label>
            Leírás:
            <input name="description" required />
        </label> <br>
        <label>
            Plakát:
            <input name="image" type="file" accept="image/jpeg" required />
        </label> <br>
        <button type="submit">Létrehoz</button>
    </form>
</div>
</body>
</html>
