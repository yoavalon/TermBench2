<?php

function transform_coordinates($x, $y, $z, $a, $b, $c) {
    $x_new = $a * $x + $b * $y + $c * $z;
    $y_new = $b * $x - $a * $y + $c * $z;
    $z_new = $c * $x + $c * $y - $a * $z;
    return array($x_new, $y_new, $z_new);
}

function main() {
    list($x, $y, $z) = array(1, 2, 3);
    list($a, $b, $c) = array(0, 1, 0);
    list($x_new, $y_new, $z_new) = transform_coordinates($x, $y, $z, $a, $b, $c);
    echo $x_new . ' ' . $y_new . ' ' . $z_new;
}

main();
?>