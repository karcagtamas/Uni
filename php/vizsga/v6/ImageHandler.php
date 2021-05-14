<?php


class ImageHandler
{
    private static string $ImagePath = "/home/karcagtamas/temp/php/images/";

    public function __construct() {
        if (!file_exists(self::$ImagePath)) {
           mkdir(self::$ImagePath, 0777, true);
        }
    }

    public function getImageUri(string $uri): string {
        return self::$ImagePath.$uri;
    }

    public function saveImage(string $name, string $tempUri): void {
        copy($tempUri, self::$ImagePath.$name);
    }
}