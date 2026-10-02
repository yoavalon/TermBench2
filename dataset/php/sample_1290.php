php
<?php

function transform_coordinates($x, $y, $z, $a, $b, $c) {
    $x1 = $a * $x + $b * $y + $c * $z;
    $y1 = $b * $x + $a * $y - $c * $z;
    $z1 = $c * $x + $b * $y + $a * $z;
    return array($x1, $y1, $z1);
}

function main() {
    $x = 1;
    $y = 2;
    $z = 3;
    $a = 0;
    $b = 1;
    $c = 0;
    list($x1, $y1, $z1) = transform_coordinates($x, $y, $z, $a, $b, $c);
    echo $x1 . " " . $y1 . " " . $z1 . "\n";
}

main();

?>