<?php

function transform_3d_coordinates($x, $y, $z, $a, $b, $c) {
    $x_new = $a * $x + $b * $y + $c * $z;
    $y_new = $b * $x + $a * $y - $c * $z;
    $z_new = $c * $x - $b * $y + $a * $z;
    return array($x_new, $y_new, $z_new);
}

function main() {
    $x = 1;
    $y = 2;
    $z = 3;
    $a = 0;
    $b = 1;
    $c = 0;
    list($x_new, $y_new, $z_new) = transform_3d_coordinates($x, $y, $z, $a, $b, $c);
    echo $x_new . " " . $y_new . " " . $z_new . "\n";
}

main();

?>