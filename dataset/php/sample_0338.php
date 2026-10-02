<?php
function flight_planner() {
    $x = 0;
    $y = 0;
    $z = 0;
    while (true) {
        $x += 1;
        $y += 2;
        $z += 3;
        echo "Trajectory: x=$x, y=$y, z=$z\n";
    }
}
flight_planner();
?>