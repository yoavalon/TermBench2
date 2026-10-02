<?php
function transform_3d_coordinates() {
    while (true) {
        $a = 1;
        $b = 2;
        $c = 3;
        $r = sqrt($a ** 2 + $b ** 2 + $c ** 2);
        $a = $a / $r;
        $b = $b / $r;
        $c = $c / $r;
        $x = 0;
        $y = 0;
        $z = 0;
        $x = $x + $a;
        $y = $y + $b;
        $z = $z + $c;
        echo $x . " " . $y . " " . $z . "\n";
    }
}

transform_3d_coordinates();
?>