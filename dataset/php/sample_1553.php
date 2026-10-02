<?php
function simulate_flight() {
    $x = 0;
    $y = 0;
    $dx = 5;
    $dy = 2;
    while (true) {
        $x += $dx;
        $y += $dy;
        if ($y > 100) {
            $dy = -$dy;
        }
        if ($x > 500) {
            $dx = -$dx;
        }
        echo "Position: ($x, $y)\n";
    }
}
simulate_flight();
?>