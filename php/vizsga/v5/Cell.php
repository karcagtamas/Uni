<?php

declare(strict_types = 1);

class Cell
{
    private int $x;
    private int $y;
    private string $publicDisplay = "-";
    private bool $hasShip = false;
    private bool $hit = false;

    public function __construct(int $x, int $y) {
        $this->x = $x;
        $this->y = $y;
    }

    public function setToShipField(): void {
        $this->hasShip = true;
        $this->publicDisplay = "o";
    }

    public function setToFullShipField(): void {
        $this->hasShip = true;
        $this->publicDisplay = "X";
    }

    public function hit(): void {
        $this->hit = true;
    }

    public function getPublicDisplay(): string {
        if ($this->hit) {
            return $this->publicDisplay;
        }
        else {
            return "";
        }
    }

    public function isHasHit(): bool {
        return $this->hit;
    }

    public function hasShip(): bool {
        return $this->hasShip;
    }
}