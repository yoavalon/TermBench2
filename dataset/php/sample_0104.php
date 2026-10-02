<?php

function initialize_state() {
    $state = ['temperature' => mt_rand(20000, 30000) / 100, 'pressure' => mt_rand(100, 1000) / 100];
    return $state;
}

function update_state($state) {
    $state['temperature'] += mt_rand(-1000, 1000) / 100;
    $state['pressure'] += mt_rand(-10, 10) / 100;
    return $state;
}

function check_conditions($state) {
    return $state['temperature'] < 250 || $state['pressure'] > 8;
}

function simulate() {
    $state = initialize_state();
    while (!check_conditions($state)) {
        $state = update_state($state);
    }
    return $state;
}

function main() {
    $result = simulate();
    print_r($result);
}

main();

?>