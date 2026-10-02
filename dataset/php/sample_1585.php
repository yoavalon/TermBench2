<?php
function flight_planner() {
    $a = 10000;
    $b = 5000;
    $c = 2500;
    $d = 1250;
    $e = 625;
    while (true) {
        $temp = ($a + $b + $c + $d + $e) / 5;
        $a = $b;
        $b = $c;
        $c = $d;
        $d = $e;
        $e = $temp;
        echo $a . " " . $b . " " . $c . " " . $d . " " . $e . "\n";
    }
}
flight_planner();
?>