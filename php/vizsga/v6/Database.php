<?php
declare(strict_types = 1);

class Database
{
    private mysqli|null|false $db;

    public function __construct(string $host, string $username, string $password, string $database) {
        $this->db  = mysqli_connect($host, $username, $password, $database) or die("Unable to connecto to the database");
    }

    public function getMovies($limit = -1): array {
        if ($this->db) {
            $limitText = $limit != -1 ? "LIMIT $limit" : "";
            $res = $this->db->query("SELECT f.id, f.cim, f.plakat, f.leiras FROM film f LEFT JOIN szavazat s ON s.film_id = f.id GROUP BY f.id ORDER BY AVG(s.szavazat) DESC {$limitText};");
            $array = [];

            while ($row = $res->fetch_assoc()) {
                array_push($array, new Movie(intval($row["id"]), $row["cim"], $row["plakat"], $row["leiras"]));
            }

            return $array;
        }

        return [];
    }

    public function addRate(int $id, int $rate): void {
        if ($this->db) {
            $this->db->query("INSERT INTO szavazat(film_id, szavazat) VALUES({$id}, {$rate});");
        }
    }

    public function addMovie(string $title, string $image, string $description): void {
        if ($this->db) {
            $this->db->query("INSERT INTO film(cim, leiras, plakat) VALUES('{$title}', '{$description}', '{$image}');");
        }
    }

    public function getMovieRate(int $id): float {
        if ($this->db) {
            $res = $this->db->query("SELECT * FROM szavazat WHERE film_id = $id;");
            $sum = 0;
            $c = 0;
            while ($row = $res->fetch_assoc()) {
                $sum += intval($row["szavazat"]);
                $c++;
            }

            if ($c == 0) {
                return -1;
            }

            return $sum / (float)$c;
        }

        return -1;
    }
}