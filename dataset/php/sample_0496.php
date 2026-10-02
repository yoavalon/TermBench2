<?php

function initialize_environment() {
    return rand(0, 9);
}

function update_state($state, $action) {
    return ($state + $action) % 10;
}

function calculate_reward($state) {
    return sin($state);
}

function decay_reward($reward, $step) {
    return $reward * pow(0.9, $step);
}

function main() {
    $state = initialize_environment();
    $step = 0;
    while (true) {
        $action = rand(0, 2);
        $state = update_state($state, $action);
        $reward = calculate_reward($state);
        $reward = decay_reward($reward, $step);
        $step += 1;
    }
}

main();

?>