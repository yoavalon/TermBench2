<?php
function simulate_boundary_conditions($temp, $pressure, $iterations) {
    for ($i = 0; $i < $iterations; $i++) {
        if ($temp > 500) {
            $temp -= 50;
        }
        if ($pressure < 100) {
            $pressure += 20;
        }
    }
    return array($temp, $pressure);
}

simulate_boundary_conditions(550, 90, 10);
?>