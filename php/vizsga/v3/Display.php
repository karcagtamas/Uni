<?php


class Display
{
    public function displaySubjectSelect(array $subjects): void {
        $s = "<select name='subject'>";

        foreach ($subjects as $subject) {
            $s .= "<option value='{$subject->getCode()}'>{$subject->getName()}</option>";
        }

        $s .= "</select>";
        echo $s;
    }

    public function displayForm(array $subjects): void {
        $s = "<form method='get' action='subject.php'>";
        echo $s;
        $this->displaySubjectSelect($subjects);
        $s = "<br><button type='submit'>Mehet</button>";
        $s .= "</form>";

        echo $s;
    }

    public function displaySubject(Subject $subject): void {
        echo <<< HTML
            <div>
                {$subject}
            </div>
        HTML;
    }

    public function displayPrevTable(array $prevs): void {
        if (count($prevs) == 0) {
            echo "Nincsenek előtanulmányi követelmények";
        }
        else {
            $s = "<table border='1'>";

            foreach($prevs as $prev) {
                $s .= "<tr>";
                $s .= "<td>{$prev->getSubject()->getCode()}</td>";
                $s .= "<td>{$prev->getSubject()->getName()}</td>";
                $s .= "</tr>";
            }

            $s .= "</table>";

            echo $s;
        }
    }

    public function displayBackToHomeButton(): void {
        echo "<br><a href='main.php'>Vissza..</a>";
    }

    public function displayHr(): void {
        echo "<hr>";
    }

    public function displayPeriodSelectorForm(array $subjects): void {
        $s = "<form action='{$_SERVER["PHP_SELF"]}' method='post'>";
        $s .= "<select name='period'><option value='1'>Őszi</option><option value='0'>Tavaszi</option></select><br>";
        foreach ($subjects as $subject) {
            $s .= "<div><input type='checkbox' name='subjects[]' value='{$subject->getCode()}'>{$subject->getName()}</input></div>";
        }
        $s .= "<button type='submit'>Mehet</button>";
        $s .= "</form>";

        echo $s;
    }
}