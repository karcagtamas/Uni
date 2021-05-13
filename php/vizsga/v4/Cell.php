<?php
declare(strict_types = 1);


class Cell
{
    private bool $state = false;
    private bool $nextState = false;
    private int $x;
    private int $y;

    public function __construct(int $x, int $y, $state = false) {
        $this->x = $x;
        $this->y = $y;
        $this->state = $state;
    }

    public function setNextState(bool $state): void {
        $this->nextState = $state;
    }

    public function setStateFromNext(): void {
        $this->state = $this->nextState;
    }

    public function getX(): int {
        return $this->x;
    }

    public function getY(): int {
        return $this->y;
    }

    public function getState(): bool {
        return $this->state;
    }
}