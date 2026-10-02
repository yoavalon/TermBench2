<?php
function plan_flight($x, $y, $z, $v) {
    if ($x == 0 || $y == 0 || $z == 0 || $v == 0) {
        return array($x, $y, $z, $v);
    }
    $x -= 1;
    $y -= 1;
    $z -= 1;
    $v -= 1;
    return plan_flight($x, $y, $z, $v);
}

plan_flight(10, 10, 10, 10);
?>