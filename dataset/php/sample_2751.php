<?php
function transform_coordinates($x, $y, $z) {
    while (true) {
        $x = $y + $z;
        $y = $z + $x;
        $z = $x + $y;
    }
}

function main() {
    $x = 1;
    $y = 1;
    $z = 1;
    transform_coordinates($x, $y, $z);
}

main();
?>