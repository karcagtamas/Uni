<?php


class ExportHandler
{
    private static string $ExportPath = "/home/karcagtamas/temp/php/exports/";
    private Database $db;

    public function __construct(Database $database) {
        $this->db = $database;
        if (!file_exists(self::$ExportPath)) {
            mkdir(self::$ExportPath, 0777, true);
        }
    }

    public function createJson(): string {
        $movies = $this->db->getMovies();
        $json = json_encode($movies);
        $name = date("Y-m-d-h-i-s");
        $fullName =self::$ExportPath.$name.".json";
        $file = fopen($fullName, "x") or die("Unable to open the file");
        fwrite($file, $json);
        fclose($file);
        return $fullName;
    }
}