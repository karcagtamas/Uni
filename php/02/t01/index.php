<!DOCTYPE>
<?php
    $data = [];
    $presents = [];

    $f = fopen("jolviselkedok.txt", "r") or die("Unable to open file");

    while(!feof($f)) {
        $key = fgets($f);
        $val = fgets($f);

        if ($key === false || $val === false) {
            continue;
        }

        $data[$key] = floatval($val);
    }

    fclose($f);

    $f = fopen("ajandekok.txt", "r") or die("Unable to open file");

    while(!feof($f)) {
        $key = fgets($f);
        $val = fgets($f);

        if ($key === false || $val === false) {
            continue;
        }

        $presents[$key] = floatval($val);
    }

    fclose($f);

    arsort($data);
    arsort($presents);

?>
<html>
<head></head>
<body>
<ol>
    <?php
        $list = [];
        foreach ($data as $key => $row) {
            array_push($list, $key);
        }

        $i = 0;
        foreach ($presents as $key => $row) {
            $list[$i] .= " - ".$key;
            $i++;
        }

        foreach ($list as $row) {
            echo "<li>".$row."</li>";
        }
    ?>
</ol>

<table>
    <tr>
        <th>Név</th>
        <th>Pont</th>
    </tr>
    <?php
    foreach ($data as $key => $row) {
        echo '<tr>';
        echo '<td>'.$key.'</td>';
        echo '<td>'.$row.'</td>';
        echo '</tr>';
    }

    ?>
</table>

<table>
    <tr>
        <th>Ajándék</th>
        <th>Érték</th>
    </tr>
    <?php
    foreach ($presents as $key => $row) {
        echo '<tr>';
        echo '<td>'.$key.'</td>';
        echo '<td>'.$row.'</td>';
        echo '</tr>';
    }

    ?>
</table>

</body>
</html>