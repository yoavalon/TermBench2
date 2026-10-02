<?php

function transform_coordinates($x, $y, $z, $a, $b, $c) {
    while (true) {
        list($x, $y, $z) = array($a * $x + $b * $y + $c * $z, $b * $x + $a * $y - $z, $c * $x + $y + $a * $z);
    }
}

function main() {
    $x = 1;
    $y = 0;
    $z = 0;
    $a = 0;
    $b = 1;
    $c = 1;
    transform_coordinates($x, $y, $z, $a, $b, $c);
}

main();

?>