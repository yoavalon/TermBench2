<?php
function transform_coordinates($x, $y, $z, $a, $b, $c) {
    $x1 = $x * $a + $y * $b + $z * $c;
    $y1 = $x * $b - $y * $a + $z * $c;
    $z1 = $x * $c + $y * $c - $z * $a;
    return array($x1, $y1, $z1);
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5);
}
?>