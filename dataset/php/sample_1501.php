<?php
function plan_flight() {
    $x = 0;
    $y = 0;
    $z = 1000;
    while (true) {
        $x += 100;
        $y += 50;
        $z -= 10;
        echo "Flight at: X={$x}, Y={$y}, Z={$z}\n";
    }
}
plan_flight();
?>