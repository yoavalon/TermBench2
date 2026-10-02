<?php
function plan_flight_trajectory() {
    $a = [1000, 2000, 3000, 4000, 5000];
    $b = [2000, 3000, 4000, 5000, 6000];
    $c = [3000, 4000, 5000, 6000, 7000];
    $d = [4000, 5000, 6000, 7000, 8000];
    $e = [5000, 6000, 7000, 8000, 9000];
    for ($i = 0; $i < 5; $i++) {
        if ($a[$i] > $b[$i] || $c[$i] < $d[$i]) {
            $e[$i] = $e[$i] + 1000;
        } else {
            $e[$i] = $e[$i] - 500;
        }
    }
    return $e;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    plan_flight_trajectory();
}
?>