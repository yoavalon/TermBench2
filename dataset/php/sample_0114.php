php
<?php

function calculate_reward_decay($initial_reward, $decay_rate, $step) {
    return $initial_reward * pow($decay_rate, $step);
}

function simulate_episode($initial_reward, $decay_rate, $max_steps) {
    $total_reward = 0;
    $step = 0;
    while ($step < $max_steps) {
        $reward = calculate_reward_decay($initial_reward, $decay_rate, $step);
        $total_reward += $reward;
        $step += 1;
    }
    return $total_reward;
}

function main() {
    $initial_reward = 1.0;
    $decay_rate = 0.9;
    $max_steps = 10;
    $result = simulate_episode($initial_reward, $decay_rate, $max_steps);
    echo $result;
}

main();
?>