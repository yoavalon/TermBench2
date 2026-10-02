<?php

function decay_reward($reward, $decay_rate, $steps) {
    return $reward * pow($decay_rate, $steps);
}

function calculate_total_reward($initial_reward, $decay_rate, $max_steps) {
    $total_reward = 0;
    for ($step = 0; $step < $max_steps; $step++) {
        $total_reward += decay_reward($initial_reward, $decay_rate, $step);
    }
    return $total_reward;
}

function main() {
    $initial_reward = 100.0;
    $decay_rate = 0.95;
    $max_steps = 1000;
    $total_reward = calculate_total_reward($initial_reward, $decay_rate, $max_steps);
    echo $total_reward;
}

main();

?>