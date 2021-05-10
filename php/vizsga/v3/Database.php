<?php
declare(strict_types = 1);

class Database
{
    private mysqli|null|false $db;

    public function __construct(string $host, string $username, string $password, string $database) {
        $this->db  = mysqli_connect($host, $username, $password, $database) or die("Unable to connecto to the database");
    }

    public function getSubjects(): array {
        if ($this->db) {
            $res = $this->db->query("SELECT * FROM kotelezo ORDER BY megnevezes;");
            $array = [];

            while ($row = $res->fetch_assoc()) {
                array_push($array, new Subject($row["kod"], $row["megnevezes"], intval($row["af"])));
            }

            return $array;
        }

        return [];
    }

    public function getSubject(string $code): Subject | null {
        if ($this->db) {
            $res = $this->db->query("SELECT * FROM kotelezo WHERE kod = '{$code}';");
            $row = $res->fetch_assoc();

            return new Subject($row["kod"], $row["megnevezes"], intval($row["af"]));
        }

        return null;
    }

    public function getPrevs(string $code): array {
        if ($this->db) {
            $res = $this->db->query("SELECT * FROM elotanulmany WHERE kod = '{$code}';");
            $array = [];

            while ($row = $res->fetch_assoc()) {
                array_push($array, new Prev($this->getSubject($row["elotanulmany"])));
            }

            return $array;
        }

        return [];
    }

    public function getAllPrevs(string $code): array {
        if ($this->db) {
            $array = $this->getPrevs($code);

            foreach ($array as $prev) {
                $next = $this->getAllPrevs($prev->getSubject()->getCode());
                if (count($next) > 0) {
                    $array = array_merge($array, $next);
                }
            }
            
            return $array;
        }

        return [];
    }
}