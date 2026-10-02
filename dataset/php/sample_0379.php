<?php

function simulate_boundary_conditions() {
    $state = 0;
    while (true) {
        $state = ($state + 1) % 100;
        echo "State: " . $state . "\n";
    }
}

simulate_boundary_conditions();

?>