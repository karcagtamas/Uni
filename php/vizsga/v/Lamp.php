<?php

class Lamp implements JsonSerializable
{
    private int $id;
    private string $description;
    private int $r;
    private int $g;
    private int $b;

    public function __construct(int $id, string $description, int $r, int $g, int $b) {
        $this->id = $id;
        $this->description = $description;
        $this->r = $r;
        $this->g = $g;
        $this->b = $b;
    }

    public function getFullName(): string {
        return $this->description." (".$this->id.")";
    }

    public function getId(): int {
        return $this->id;
    }

    public function getDescription(): string {
        return $this->description;
    }

    public function getR(): int {
        return $this->r;
    }

    public function getG(): int {
        return $this->g;
    }

    public function getB(): int {
        return $this->b;
    }

    public function getHexColor(): string {
        return "#".$this->getHex($this->getR()).$this->getHex($this->getG()).$this->getHex($this->getB());
    }

    private function getHex(int $color): string {
        $hex = dechex($color);
        return strlen($hex) == 1 ? "0".$hex : $hex;
    }

    public function setHexColor(string $color): void {
        if (strlen($color) != 7) {
            return;
        }

        $this->r = $this->getDec(substr($color, 1, 2));
        $this->g = $this->getDec(substr($color, 3, 2));
        $this->b = $this->getDec(substr($color, 5, 2));
    }

    private function getDec(string $color): int {
        return hexdec($color);
    }

    public function jsonSerialize(): array
    {
        return [
            'id' => $this->id,
            'description' => $this->description,
            'r' => $this->r,
            'g' => $this->g,
            'b' => $this->b
        ];
    }
}