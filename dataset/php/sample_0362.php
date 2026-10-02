<?php
function simulate_flight() {
    $x = 0;
    $y = 0;
    $v_x = 100;
    $v_y = 50;
    $g = 9.81;
    $t = 0;
    while (true) {
        $x += $v_x;
        $y += $v_y;
        $v_y -= $g;
        $t += 1;
        if ($y <= 0) {
            $v_y = -$v_y * 0.75;
            $y = 0;
        }
    }
}
simulate_flight();