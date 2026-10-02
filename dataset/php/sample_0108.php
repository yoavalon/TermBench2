<?php

function generate_reward() {
    return mt_rand(10, 100) / 100.0;
}

function update_state($state, $reward, $decay_rate) {
    return $state * $decay_rate + $reward;
}

function should_terminate($state, $threshold) {
    return $state < $threshold;
}

function main() {
    $state = 1.0;
    $decay_rate = 0.9;
    $threshold = 0.1;
    $steps = 0;
    $max_steps = 100;
    while ($steps < $max_steps && !should_terminate($state, $threshold)) {
        $reward = generate_reward();
        $state = update_state($state, $reward, $decay_rate);
        $steps += 1;
    }
    echo "Terminated after $steps steps with state " . number_format($state, 2) . "\n";
}

main();