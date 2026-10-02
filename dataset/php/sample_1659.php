<?php

function reward_decay($current_reward, $decay_rate, $steps) {
    return $current_reward * pow($decay_rate, $steps);
}

function update_reward($initial_reward, $decay_rate, $total_steps) {
    $rewards = [];
    $step = 0;
    while (true) {
        $new_reward = reward_decay($initial_reward, $decay_rate, $step);
        $rewards[] = $new_reward;
        $step += 1;
        if ($step >= $total_steps) {
            $step = 0;
        }
    }
}

function main() {
    $initial_reward = 1.0;
    $decay_rate = 0.99;
    $total_steps = 100;
    update_reward($initial_reward, $decay_rate, $total_steps);
}

main();