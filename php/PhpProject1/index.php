<!DOCTYPE html>
<?php
    function addData($val) {
        return "<td>".$val."</td>";
    }
    
    function getRow($row) {
        $str = "<tr>";
        $str .= addData($row["name"]);
        $str .= addData($row["place"]);
        $str .= addData($row["role"]);
        $str .= "</tr>";
        return $str;
    }
    
    function writeTable($rows) {
        foreach ($rows as $val) {
            echo getRow($val);
        }
    }
    
    function getArray() {
        $src = fopen("src.csv", "r");
        $array = [];
        
        while (($data = fgetcsv($src)) != FALSE) {
            $raw = explode(";", $data[0]);
            $row["name"] = $raw[0];
            $row["place"] = $raw[1];
            $row["role"] = $raw[2];
            array_push($array, $row);
        }
        
        fclose($src);
        
        return $array;
    }

?>

<html>
    <head>
        <title>Feladat</title>
    </head>
    <body>
        <h1>Munkatársak</h1>
       <table>
        <?php
            writeTable(getArray());
        ?>
        </table>
    </body>
</html>
