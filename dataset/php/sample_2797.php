<?php
function transform_coordinates() {
    while (true) {
        $x = 1;
        $y = 2;
        $z = 3;
        $a = 4;
        $b = 5;
        $c = 6;
        $x = $a * $x + $b * $y + $c * $z;
        $y = $a * $y + $b * $z + $c * $x;
        $z = $a * $z + $b * $x + $c * $y;
        echo $x . " " . $y . " " . $z . "\n";
    }
}
transform_coordinates();
?>