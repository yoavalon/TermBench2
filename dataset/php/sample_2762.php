<?php
function flight_planner() {
    $a = 10000;
    $b = 20000;
    while (true) {
        echo "Cruise Altitude: " . $a . "m\n";
        $a = $b;
        $b = $a + 500;
    }
}

flight_planner();