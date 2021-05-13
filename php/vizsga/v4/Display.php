<?php
declare(strict_types = 1);

class Display
{
    public function drawTable(int $size, array $table, bool $started): void {
        $s = "<form method='post' action='{$_SERVER['PHP_SELF']}'><table>";
        for ($i = 0; $i < $size; $i++) {
            $s .= "<tr>";
            for ($j = 0; $j < $size; $j++) {
                $disabled = $started ? " disabled" : "";
                $checked = $table[$i][$j]->getState() ? " checked" : "";
                $s .= "<td><input type='checkbox' name='alive[]' value='{$i}-{$j}' {$disabled} {$checked} /></td>";
            }
            $s .= "</tr>";
        }
        $s .= "</table>{$this->startButton($started ? "Következő állapot" : "Start")}";
        $s .= "</form>";
        echo $s;
    }

    private function startButton(string $text): string {
        return "<button type=''>{$text}</button>";
    }
}