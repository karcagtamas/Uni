<?php


class JsonExport
{
    private static string $ExportPath = "./exports/";
    private Database $db;

    public function __construct() {
        $this->db = new Database();
        if (!file_exists(self::$ExportPath)) {
            mkdir(self::$ExportPath, 0777, true);
        }
    }

    public function exportLamps(): string {
        $lamps = $this->db->getLamps();
        $json = json_encode($lamps, JSON_UNESCAPED_UNICODE);
        $name = date("Y-m-d-h-i-s");
        $fullName =self::$ExportPath.$name.".json";
        $file = fopen($fullName, "x") or die("Unable to open the file");
        fwrite($file, $json);
        fclose($file);
        return $fullName;
    }
}