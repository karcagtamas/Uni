<?php

declare(strict_types = 1);

class Table
{
    private int $height = 10;
    private int $width = 10;
    private array $table;
    private bool $hasShips = false;
    private const SHIP_NUMBER = 4;
    private int $hits = 0;
    private array $ships;

    public function __construct(int $height = 10, int $width = 10) {
        $this->height;
        $this->width;

        $array = [];
        for($i = 0; $i < $this->height; $i++) {
            $sub = [];
            for($j = 0; $j < $this->width; $j++) {
                array_push($sub, new Cell($i, $j));
            }
            array_push($array, $sub);
        }
        $this->table = $array;
        $this->initShips();
    }

    public function initShips(): void {
        if (!$this->hasShips) {
            $this->ships = [];
            $this->hasShips = true;
            for ($i = 0; $i < self::SHIP_NUMBER; $i++) {
                $found = false;
                do {
                    $x = random_int(0, $this->height - 2);
                    $y = random_int(0, $this->width - 2);
                    $found = $this->shipIsValid($x, $y);
                } while(!$found);

                $this->setShip($x, $y);
            }
        }
    }

    public function display(): void {
        $s = "";
        if ($this->isEnd()) {
            $s .= "<form action='{$_SERVER['PHP_SELF']}' method='get'><input name='reset' type='number' value='1' hidden /><button type='submit'>Reset</button></form>";
        }
        else {
            $s .= "<table>";
            for ($i = 0; $i < $this->height; $i++) {
                $s .= "<tr>";
                for ($j = 0; $j < $this->width; $j++) {
                    $disabled = $this->table[$i][$j]->isHasHit();
                    $s .= "<td>";
                    if (!$disabled) {
                        $s .= "<form method='get' action='{$_SERVER['PHP_SELF']}'><input type='number' name='cellx' value='{$i}' hidden/><input type='number' name='celly' value='{$j}' hidden/>";
                    }
                    $s .= "<button type='submit' >{$this->table[$i][$j]->getPublicDisplay()}</button></td>";
                    if (!$disabled) {
                        $s .= "</form>";
                    }
                }
                $s .= "</tr>";
            }
            $s .= "</table>";
        }

        echo $s;
    }

    public function hitField(int $x, int $y) {
        $this->table[$x][$y]->hit();
        $this->hits++;

        if ($this->table[$x][$y]->hasShip()) {
            foreach ($this->ships as $ship) {
                if ($ship->contains($x, $y)) {
                    $ship->hit();

                    if ($ship->dead()) {
                        $this->setFullDead($ship->getX(), $ship->getY());
                    }
                    break;
                }
            }
        }
    }

    public function getHits(): int {
        return $this->hits;
    }

    private function shipIsValid(int $x, int $y): bool {
        return !$this->table[$x][$y]->hasShip() && !$this->table[$x + 1][$y]->hasShip() && !$this->table[$x][$y + 1]->hasShip() && !$this->table[$x + 1][$y + 1]->hasShip();
    }

    private function setShip(int $x, int $y): void {
        $this->table[$x][$y]->setToShipField();
        $this->table[$x + 1][$y]->setToShipField();
        $this->table[$x][$y + 1]->setToShipField();
        $this->table[$x + 1][$y + 1]->setToShipField();
        array_push($this->ships, new Ship($x, $y));
    }

    private function setFullDead(int $x, int $y): void {
        $this->table[$x][$y]->setToFullShipField();
        $this->table[$x + 1][$y]->setToFullShipField();
        $this->table[$x][$y + 1]->setToFullShipField();
        $this->table[$x + 1][$y + 1]->setToFullShipField();
    }

    public function isEnd(): bool {
        foreach ($this->ships as $ship) {
            if (!$ship->dead()) {
                return false;
            }
        }

        return true;
    }
}