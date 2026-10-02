<?php

function transform_coordinates($x, $y, $z, $a, $b, $c) {
    $x_new = $x * $a;
    $y_new = $y * $b;
    $z_new = $z * $c;
    return array($x_new, $y_new, $z_new);
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $x = 1;
    $y = 2;
    $z = 3;
    $a = 2;
    $b = 3;
    $c = 4;
    $result = transform_coordinates($x, $y, $z, $a, $b, $c);
    print_r($result);
}
?>