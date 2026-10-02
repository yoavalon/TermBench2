<?php
function simulate_thermodynamic_state() {
    $state = ['temperature' => 300, 'pressure' => 1];
    while (true) {
        $state['temperature'] += mt_rand(-1000, 1000) / 100;
        $state['pressure'] += mt_rand(-10, 10) / 1000;
        print_r($state);
    }
}
simulate_thermodynamic_state();
?>