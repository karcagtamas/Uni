<?php


class Movie implements JsonSerializable
{
    private int $id;
    private string $title;
    private string $imageUri;
    private string $description;

    public function __construct(int $id, string $title, string $imageUri, string $description) {
        $this->id = $id;
        $this->title = $title;
        $this->imageUri = $imageUri;
        $this->description = $description;
    }

    public function displayCard(Database $db): void {
        $imageHandler = new ImageHandler();
        $rate = $db->getMovieRate($this->id);
        $rateDisplay = $rate == -1 ? "--" : $rate;
        $s = "<div>";
        $s .= "<div><img width='100' height='100' src='{$imageHandler->getImageUri($this->imageUri)}' /></div>";
        $s .= "<div>{$this->title}</div>";
        $s .= "<div>{$rateDisplay}</div>";
        $s .= "<form method='post' action='{$_SERVER['PHP_SELF']}'><div><input name='id' type='number' value='{$this->id}' hidden /><input type='number' min='0' max='10' value='0' name='rate' required /></div>";
        $s .= "<div><button type='submit'>Leadás</button></div></form>";
        $s .= "</div> <br>";

        echo $s;
    }

    public function jsonSerialize(): array
    {
        return
            [
                'id'   => $this->id,
                'title' => $this->title,
                'imageUri' => $this->imageUri,
                'description' => $this->description
            ];
    }
}