<?php

declare(strict_types = 1);

spl_autoload_register(function ($name) {
    require_once "$name.php";
});

class Game
{
    private string $status = "init";
    private int $size = 20;
    private array $cells;

    private Display $display;

    public function __construct(int $size, array $cells = []) {
        $this->size = $size;
        if (!empty($cells)) {
            $this->status = "started";
            $array = [];
            for ($i = 0; $i < $this->size; $i++) {
                $sub = [];
                for ($j = 0; $j < $this->size; $j++) {
                    $found = array_search("{$i}-{$j}", $cells);
                    $cell = new Cell($i, $j, $found !== false);
                    array_push($sub, $cell);
                }
                array_push($array, $sub);
            }
        }else {
            $array = [];
            for ($i = 0; $i < $this->size; $i++) {
                $sub = [];
                for ($j = 0; $j < $this->size; $j++) {
                    $cell = new Cell($i, $j);
                    array_push($sub, $cell);
                }
                array_push($array, $sub);
            }
        }
        $this->cells = $array;

        $this->display = new Display();
    }

    public function init(): void {
        if ($this->status == "init") {
            $this->display->drawTable($this->size, $this->cells, false);
        }
    }

    public function start(): void {
        if ($this->status == "started") {
            $this->determineNextState();
            $this->activateNextState();
            $this->display->drawTable($this->size, $this->cells, true);
        }
    }

    private function determineNextState(): void {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $c = $this->getNeighbourCount($i, $j);

                if ($this->cells[$i][$j]->getState()) {
                    if ($c == 3 || $c == 4) {
                        $this->cells[$i][$j]->setNextState(true);
                    }else {
                        $this->cells[$i][$j]->setNextState(false);
                    }
                }
                else {
                    if ($c == 3) {
                        $this->cells[$i][$j]->setNextState(true);
                    }
                }
            }
        }
    }

    private function activateNextState(): void {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $this->cells[$i][$j]->setStateFromNext();
            }
        }
    }

    private function getNeighbourCount(int $x, int $y): int {
        $c = 0;
        $ic = 0;
        $startX = $this->getPrev($x);
        while($ic < 3) {
            $jc = 0;
            $startY = $this->getPrev($y);

            while($jc < 3) {
                    if ($this->cells[$startX][$startY]->getState()) {
                        $c++;
                    }

                $startY = $this->getNext($startY);
                $jc++;
            }

            $startX = $this->getNext($startX);
            $ic++;
        }
        var_dump($c);
        return $c - 1;
    }

    private function getNext(int $num): int {
        if ($num == $this->size - 1) {
            return 0;
        }
        else {
            return $num + 1;
        }
    }

    private function getPrev(int $num): int {
        if ($num == 0) {
            return $this->size - 1;
        }
        else {
            return $num - 1;
        }
    }
}