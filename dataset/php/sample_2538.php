<?php

function compute_reward_decay($reward, $decay_rate, $steps) {
    return $reward * pow($decay_rate, $steps);
}

function simulate_sequence($initial_reward, $decay_rate, $max_steps) {
    $sequence = [];
    $current_reward = $initial_reward;
    for ($step = 0; $step < $max_steps; $step++) {
        $current_reward = compute_reward_decay($current_reward, $decay_rate, 1);
        array_push($sequence, $current_reward);
    }
    return $sequence;
}

function main() {
    $initial_value = 100;
    $decay_factor = 0.95;
    $total_iterations = 10;
    $result = simulate_sequence($initial_value, $decay_factor, $total_iterations);
    print_r($result);
}

main();