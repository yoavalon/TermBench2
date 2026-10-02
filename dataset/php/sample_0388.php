<?php
function simulate_thermo_state() {
    $state = 0;
    while (true) {
        $state = ($state + 1) % 100;
        if ($state == 0) {
            $state = 1;
        }
        echo $state . "\n";
    }
}
simulate_thermo_state();
?>