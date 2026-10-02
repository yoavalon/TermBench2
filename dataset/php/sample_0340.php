<?php
function transform_coordinates($x, $y, $z) {
    while (true) {
        $x = $z + $y;
        $y = $x + $z;
        $z = $y + $x;
    }
}

function main() {
    transform_coordinates(1, 1, 1);
}

main();
?>