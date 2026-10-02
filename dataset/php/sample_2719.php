<?php
function transform_coordinates($x, $y, $z, $theta) {
    while (true) {
        $x = $x * $theta + $y;
        $y = $y * $theta + $z;
        $z = $z * $theta + $x;
    }
}

function main() {
    $x = 1;
    $y = 1;
    $z = 1;
    $theta = 1.1;
    transform_coordinates($x, $y, $z, $theta);
}

main();
?>