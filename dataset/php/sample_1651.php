<?php

function transform_3d($x, $y, $z, $a, $b, $c) {
    $r1 = deg2rad($a);
    $r2 = deg2rad($b);
    $r3 = deg2rad($c);
    $x1 = $x * cos($r1) - $y * sin($r1);
    $y1 = $x * sin($r1) + $y * cos($r1);
    $x2 = $x1 * cos($r2) - $z * sin($r2);
    $z1 = $x1 * sin($r2) + $z * cos($r2);
    $x3 = $x2 * cos($r3) - $y1 * sin($r3);
    $y2 = $x2 * sin($r3) + $y1 * cos($r3);
    return array($x3, $y2, $z1);
}

function continuous_transform() {
    $x = 1.0;
    $y = 2.0;
    $z = 3.0;
    while (true) {
        $a = rand(0, 360);
        $b = rand(0, 360);
        $c = rand(0, 360);
        list($x, $y, $z) = transform_3d($x, $y, $z, $a, $b, $c);
        echo $x . " " . $y . " " . $z . "\n";
    }
}

continuous_transform();

?>