<?php

function transform_3d_coordinates($a, $b, $c, $x, $y, $z) {
    for ($i = 0; $i < 3; $i++) {
        list($a, $b, $c) = array($b, $c, $a);
        list($x, $y, $z) = array($y, $z, $x);
    }
    return array($a, $b, $c, $x, $y, $z);
}

transform_3d_coordinates(1, 2, 3, 4, 5, 6);

?>