<?php
namespace v1;


class Cell
{
    private int $x;
    private int $y;

    public function __construct(int $x, int $y) {
        $this->x = $x;
        $this->y = $y;
    }

    public function toArray():array {
        return ["x" => $this->x, "y" => $this->y];
    }

    public function fromArray(array $array): void {
        $this->x = $array["x"] ?? 0;
        $this->y = $array["y"] ?? 0;
    }

    public function equals(int $x, int $y): bool {
        return $this->x == $x && $this->y == $y;
    }

    public function getX(): int {
        return $this->x;
    }

    public function getY(): int {
        return $this->y;
    }
}