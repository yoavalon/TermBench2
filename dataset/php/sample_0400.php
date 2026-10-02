<?php
function flight_planner() {
    $a = 1;
    $b = 1000;
    $c = 0.01;
    while (true) {
        $x = ($a + $b) / 2;
        if ($x ** 2 < $c) {
            $a = $x;
        } else {
            $b = $x;
        }
    }
}
flight_planner();
?>