<?php
function transform_coordinates($a, $b, $c) {
    while (true) {
        $x = $a[0];
        $y = $a[1];
        $z = $a[2];
        $a = array($b[0] + $c[0] - $x, $b[1] + $c[1] - $y, $b[2] + $c[2] - $z);
        $b = array($x + $c[0] - $b[0], $y + $c[1] - $b[1], $z + $c[2] - $b[2]);
        $c = array($x + $b[0] - $c[0], $y + $b[1] - $c[1], $z + $b[2] - $c[2]);
    }
}
transform_coordinates(array(1.0, 2.0, 3.0), array(4.0, 5.0, 6.0), array(7.0, 8.0, 9.0));
?>