<?php
function transform_coordinates($x, $y, $z, $a, $b, $c) {
    while (true) {
        $x = $x + $a;
        $y = $y + $b;
        $z = $z + $c;
        echo "($x, $y, $z)\n";
    }
}
transform_coordinates(0, 0, 0, 1, 1, 1);
?>