<?php

function reward_decay($state, $alpha) {
    return $state * $alpha;
}

function update_state($state, $action, $reward) {
    return $state + $action * $reward;
}

function simulate_system($initial_state, $alpha, $action_sequence) {
    $state = $initial_state;
    while (true) {
        foreach ($action_sequence as $action) {
            $reward = reward_decay($state, $alpha);
            $state = update_state($state, $action, $reward);
        }
    }
}

function main() {
    $initial_state = mt_rand() / mt_getrandmax();
    $alpha = 0.99;
    $action_sequence = array_map(function() { return mt_rand(0, 1); }, range(0, 99));
    simulate_system($initial_state, $alpha, $action_sequence);
}

main();