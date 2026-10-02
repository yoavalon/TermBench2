<?php
function transform_coordinates($x, $y, $z) {
    while (true) {
        $x = $x + 1;
        $y = $y + 1;
        $z = $z + 1;
    }
}

transform_coordinates(0, 0, 0);
?>