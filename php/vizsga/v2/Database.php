<?php


class Database
{
    private mysqli $db;

    public function __construct(string $host, string $username, string $password, string $database, int $port = 3306) {
        $this->db = mysqli_connect($host, $username, $password, $database, $port) or die("Connection unsuccesful");
    }

    public function __destruct()
    {
        mysqli_close($this->db);
    }

    public function getCities(): array {
        $res = mysqli_query($this->db, "SELECT * FROM varosok;");
        $array = [];
        while($row = mysqli_fetch_assoc($res)) {
            array_push($array, $row);
        }

        return $array;
    }

    public function getLengthBetweenTwoCity(int $city1, int $city2): int {
        $res = mysqli_query($this->db, "SELECT tavolsag FROM tavolsagok WHERE (v1 = {$city1} AND v2 = {$city2}) OR (v1 = {$city2} AND v2 = {$city1});");
        if ($row = mysqli_fetch_assoc($res)) {
            return $row["tavolsag"];
        }

        return -1;
    }
}