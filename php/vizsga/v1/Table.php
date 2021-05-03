<?php
namespace v1;

class Table
{
    private int $size = 8;
    private const START_CHAR = 'A';
    private array $queens = [];

    public function __construct(int $size = 8)
    {
        $this->size = $size;
    }

    public function setQueens(array $array) {
        foreach ($array as $cellData) {
            $cell = new Cell(0, 0);
            $cell->fromArray($cellData);
            array_push($this->queens, $cell);
        }
    }

    public function getQueens(): array {
        $arr = [];

        foreach ($this->queens as $queen) {
            array_push($arr, $queen->toArray());
        }
        
        return $arr;
    }

    private function generateCellContent(int $row, int $col, bool $checked, bool $active): string {
        $checkedText = $checked ? "checked" : "";
        if ($active) {
            return "<input type='checkbox' name='{$row}_{$col}_q' {$checkedText} >";
        }
        else {
            return "<input type='checkbox' disabled {$checkedText} >";
        }
    }

    private function isQueen(int $i, int $j): bool {
        foreach($this->queens as $queen) {
            if ($queen->equals($i, $j)) {
                return true;
            }
        }

        return false;
    }

    public function isCorrect(): bool {
        if (count($this->queens) != $this->size) {
            return false;
        }

        $rows = array_map(function($v) {
            return $v->getX();
        }, $this->queens);

        if (count(array_unique($rows, SORT_NUMERIC)) != $this->size) {
            return false;
        }

        $cols = array_map(function($v) {
            return $v->getY();
        }, $this->queens);

        if (count(array_unique($cols, SORT_NUMERIC)) != $this->size) {
            return false;
        }

        return true;
    }

    public function generate($type = 0, $active = true): string
    {
        $s = "<table>";

        for ($i = 0; $i < $this->size + 2; $i++) {
            $s .= "<tr>";
            for ($j = 0; $j < $this->size + 2; $j++) {
                $s .= "<td>";
                if ($i == 0 || $i == $this->size + 1) {
                    if ($j != 0 && $j != $this->size + 1) {
                        $s .= chr(ord(self::START_CHAR) + $j - 1);
                    }
                } else if ($j == 0 || $j == $this->size + 1) {
                    $s .= $i;
                }
                else {
                    $found = $this->isQueen($this->GetXForType($i, $j, $type), $this->getYForType($i, $j, $type));
                    $s .= $this->generateCellContent($i, $j, $found, $active);
                }
                $s .= "</td>";
            }

            $s .= "</tr>";
        }

        return $s;
    }

    private function GetXForType(int $x, int $y, int $type = 0): int {
        $resX = $x;
        $resY = $y;
        for ($i = 0; $i < $type; $i++) {
            $oldX = $resX;
            $resX = $resY;
            $resY = $this->size - ($oldX - 1);
        }
        return $resX;
    }

    private function GetYForType(int $x, int $y, int $type = 0): int {
        $resX = $x;
        $resY = $y;
        for ($i = 0; $i < $type; $i++) {
            $oldX = $resX;
            $resX = $resY;
            $resY = $this->size - ($oldX - 1);
        }
        return $resY;
    }

    public function displayGraphic(): string
    {
        $s = "<table class='graph'>";

        for ($i = 0; $i < $this->size + 2; $i++) {
            if ($i == 0 || $i == $this->size + 1) {
                $s .= "<tr>";
            }
            else {
                $s .= "<tr class='ch'>";
            }

            for ($j = 0; $j < $this->size + 2; $j++) {

                if ($i == 0 || $i == $this->size + 1) {
                    $s .= "<th>";
                    if ($j != 0 && $j != $this->size + 1) {
                        $s .= chr(ord(self::START_CHAR) + $j - 1);
                    }
                    $s .= "</th>";
                } else if ($j == 0 || $j == $this->size + 1) {
                    $s .= "<th>";
                    $s .= $i;
                    $s .= "</th>";
                }
                else {
                    $s .= "<td>";
                    $found = $this->isQueen($i, $j);
                    if ($found) {
                        $s .= "<img src='queen.png'>";
                    }
                    $s .= "</td>";
                }

            }

            $s .= "</tr>";
        }

        return $s;
    }
}