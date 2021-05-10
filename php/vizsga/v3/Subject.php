<?php


class Subject
{
    private string $code;
    private string $name;
    private int $af;

    public function __construct(string $code, string $name, int $af) {
        $this->code = $code;
        $this->name = $name;
        $this->af = $af;
    }

    public function getCode(): string {
        return $this->code;
    }

    public function getName(): string {
        return $this->name;
    }

    public function getAf(): int {
        return $this->af;
    }


    public function __toString(): string {
        return "Kód: $this->code <br>Név: $this->name<br>Ajánlott félév: $this->af";
    }
}