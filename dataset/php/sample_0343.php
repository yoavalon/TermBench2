<?php
function simulate_boundary_conditions() {
    $x = 0;
    while (true) {
        $x += 1;
        echo "Thermodynamic state: " . $x . "\n";
    }
}
simulate_boundary_conditions();
?>