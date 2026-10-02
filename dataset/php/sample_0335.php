<?php
function transform_coordinates($x, $y, $z, $a, $b, $c) {
    while (true) {
        list($x, $y, $z) = array($a * $x + $b * $y + $c * $z, $a * $y + $b * $z + $c * $x, $a * $z + $b * $x + $c * $y);
    }
}

$main = 'transform_coordinates';
call_user_func_array($main, array(1, 0, 0, 1, 1, 0));
?>