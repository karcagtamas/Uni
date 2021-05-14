<?php

class Database
{
    private mysqli|null|false $db;

    public function __construct() {
        $this->db  = mysqli_connect('xenia.sze.hu', 'hallgato', 'mysql', 'hallgatok') or die("Unable to connecto to the database");
    }

    public function getLamps(int $user = -1): array {
        if ($this->db) {
            $res = $this->db->query($this->getLampQuery($user));
            $array = [];

            while ($row = $res->fetch_assoc()) {
                array_push($array, new Lamp(intval($row["id"]), $row["description"], intval($row["r"]), intval($row["g"]), intval($row["b"])));
            }

            return $array;
        }

        return [];
    }

    private function getLampQuery(int $user): string {
        if ($user == -1) {
            return "SELECT * FROM lamps";
        } else {
            $userObj = $this->getUser($user);
            if ($userObj->isAdmin()) {
                return "SELECT * FROM lamps";
            }
            return "SELECT * FROM lamps l INNER JOIN permissions p on l.id = p.lamp_id WHERE p.permission >= 1 AND p.user_id = {$user};";
        }
    }

    public function getLamp(int $id): Lamp | null {
        if ($this->db) {
            $res = $this->db->query("SELECT * FROM lamps WHERE id = {$id};");
            if ($res->num_rows == 0) {
                return null;
            }
            $row = $res->fetch_assoc();

            return new Lamp(intval($row["id"]), $row["description"], intval($row["r"]), intval($row["g"]), intval($row["b"]));

        }

        return null;
    }

    public function getUser(int $id): User | null {
        if ($this->db) {
            $res = $this->db->query("SELECT * FROM users WHERE id = {$id};");
            if ($res->num_rows == 0) {
                return null;
            }
            $row = $res->fetch_assoc();

            return new User(intval($row["id"]), $row["name"], (bool)$row["admin"]);

        }

        return null;
    }

    public function updateLamp(Lamp $lamp): void {
        if ($this->db) {
            $this->db->query("UPDATE lamps SET description = '{$lamp->getDescription()}', r = {$lamp->getR()}, g = {$lamp->getG()}, b = {$lamp->getB()} WHERE id = {$lamp->getId()};");
        }
    }

    public function getUsers(): array {
        if ($this->db) {
            $res = $this->db->query("SELECT * FROM users;");
            $array = [];

            while ($row = $res->fetch_assoc()) {
                array_push($array, new User(intval($row["id"]), $row["name"], (bool)$row["admin"]));
            }

            return $array;
        }

        return [];
    }

    public function canSwitch(int $lamp, int $user): bool {
        if ($user == -1) {
            return false;
        }

        $userObj = $this->getUser($user);
        if ($userObj->isAdmin()) {
            return true;
        }

        if ($this->db) {
            $res = $this->db->query("SELECT * FROm permissions WHERE lamp_id = {$lamp} AND user_id = {$user} AND permission = 2;");

            if ($res->num_rows > 0) {
                return true;
            }
            else {
                return false;
            }
        }

        return false;
    }

    public function isAdmin(int $user): bool {
        $userObj = $this->getUser($user);
        if ($userObj == null) {
            return false;
        }
        
        return $userObj->isAdmin();
    }
}