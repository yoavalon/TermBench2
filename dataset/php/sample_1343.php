<?php

function decay_reward($reward, $decay_rate, $steps) {
    $rewards = array_fill(0, $steps, 0);
    $rewards[0] = $reward;
    for ($i = 1; $i < $steps; $i++) {
        $rewards[$i] = $rewards[$i - 1] * $decay_rate;
    }
    return $rewards;
}

function main() {
    $initial_reward = 100;
    $decay_rate = 0.95;
    $steps = 10;
    $rewards = decay_reward($initial_reward, $decay_rate, $steps);
    print_r($rewards);
}

main();