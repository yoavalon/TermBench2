<?php

function calculate_reward_decay($initial_reward, $decay_rate, $time_steps) {
    $rewards = array_fill(0, $time_steps, 0);
    $rewards[0] = $initial_reward;
    for ($t = 1; $t < $time_steps; $t++) {
        $rewards[$t] = $rewards[$t - 1] * (1 - $decay_rate);
    }
    return $rewards;
}

function simulate_terminal_condition($rewards, $threshold) {
    foreach ($rewards as $reward) {
        if ($reward < $threshold) {
            return true;
        }
    }
    return false;
}

function main() {
    $initial_reward = 1.0;
    $decay_rate = 0.05;
    $time_steps = 20;
    $threshold = 0.01;
    $rewards = calculate_reward_decay($initial_reward, $decay_rate, $time_steps);
    $terminal_condition = simulate_terminal_condition($rewards, $threshold);
    echo 'Terminal Condition Met: ' . ($terminal_condition ? 'true' : 'false') . "\n";
}

main();