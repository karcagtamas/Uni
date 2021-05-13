<?php


class Ship
{
    private int $x;
    private int $y;
    private int $width = 2;
    private int $height = 2;
    private int $life = 4;
    private int $hit = 0;

    public function __construct(int $x, int $y) {
        $this->x = $x;
        $this->y = $y;
    }

    public function contains(int $x, int $y): bool {
        return $x >= $this->x && $x < $this->x + $this->height && $y >= $this->y && $y < $this->y + $this->width;
    }

    public function hit(): void {
        $this->hit++;
    }

    public function dead(): bool {
        return $this->hit == $this->life;
    }

    public function getX(): int {
        return $this->x;
    }

    public function getY(): int {
        return $this->y;
    }
}