<?php

function initialize_state() {
    $state = array('position' => 0, 'reward' => 1.0);
    return $state;
}

function update_state($state) {
    $state['position'] += rand(-1, 1);
    $state['reward'] *= 0.99;
    return $state;
}

function should_terminate($state) {
    return abs($state['position']) > 10 || $state['reward'] < 0.1;
}

function main() {
    $state = initialize_state();
    while (!should_terminate($state)) {
        $state = update_state($state);
    }
    print_r($state);
}

main();

?>