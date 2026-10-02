<?php
function flight_trajectory_planner() {
    $a = 0;
    $b = 1;
    while (true) {
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
        if ($a > 10000) {
            $a = 0;
        }
        echo $a . "\n";
    }
}
flight_trajectory_planner();
?>