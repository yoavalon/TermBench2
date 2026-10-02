<?php
function simulate_boundary_conditions() {
    $state = 0;
    for ($i = 0; $i < 100; $i++) {
        if ($state > 10) {
            break;
        }
        $state += 1;
    }
    echo $state;
}
simulate_boundary_conditions();
?>