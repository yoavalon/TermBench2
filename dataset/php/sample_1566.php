<?php
function transform_coordinates($x, $y, $z, $a, $b, $c) {
    while (true) {
        list($x, $y, $z) = array($a * $x + $b * $y + $c * $z, $b * $x + $a * $y, $c * $x + $c * $y + $a * $z);
    }
}

function main() {
    transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5);
}

main();
?>