<?php


class Table
{
    private Database $db;

    public function __construct() {
        $this->db = new Database();
    }

    public function displayLampTable($user = -1): void {
        $lamps = $this->db->getLamps($user);
        $s = "<table>";
        foreach ($lamps as $lamp) {
            $s .= "<tr><form method='post' action='{$_SERVER['PHP_SELF']}'>";
            $s .= "<td>{$lamp->getFullName()}</td>";
            $canSwitch = $this->db->canSwitch($lamp->getId(), $user);
            $readonly = $canSwitch ? "" : "disabled";
            $s .= "<td><input hidden value='{$lamp->getId()}' name='id' /><input type='color' {$readonly} name='color' value='{$lamp->getHexColor()}' /></td>";
            if ($canSwitch) {
                $s .= "<td><button type='submit'>Beállít</button></td>";
            }
            $s .= "</form></tr>";
        }
        $s .= "</table>";
        echo $s;
    }

    public function displayUserSelect(): void {
        $users = $this->db->getUsers();
        $s = "<form method='post' action='main.php'>";
        $s .= "<select name='user'>";
        foreach ($users as $user) {
            $s .= "<option value='{$user->getId()}'>{$user->getName()}</option>";
        }
        $s .= "</select><br>";
        $s .= "<button type='submit'>Tovább</button>";
        $s .= "</form>";
        echo $s;
    }

    public function displayAdminTable(int $user = -1): void {
        $isAdmin = $this->db->isAdmin($user);

        if ($isAdmin) {
            $lamps = $this->db->getLamps($user);
            $users = $this->db->getUser();
            $s = "<table>";
            $s .= "<tr>";
            $s .= "<td></td>";
            foreach ($users as $user) {
                $s .= "<td>{$user->getName()}</td>";
            }
            $s .= "</tr>";

            foreach($lamps as $lamp) {
                $s .= "<tr>";
                $s .= "<td>{$lamp->getFullName()}</td>";

                foreach ($users as $user) {
                    $s .= "<td></td>";
                }
                $s .= "</tr>";
            }
            $s .= "</table>";
            echo $s;
        }
    }
}