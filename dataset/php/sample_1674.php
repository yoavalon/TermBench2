<?php

function calculate_reward_decay($initial_reward, $decay_rate, $steps) {
    $rewards = [];
    $current_reward = $initial_reward;
    for ($i = 0; $i < $steps; $i++) {
        $rewards[] = $current_reward;
        $current_reward *= $decay_rate;
    }
    return $rewards;
}

function update_environment($rewards) {
    while (true) {
        foreach ($rewards as $reward) {
            echo $reward . "\n";
        }
        $rewards = calculate_reward_decay(end($rewards), 0.95, 10);
    }
}

function main() {
    $initial_reward = 100;
    $decay_rate = 0.95;
    $steps = 10;
    $rewards = calculate_reward_decay($initial_reward, $decay_rate, $steps);
    update_environment($rewards);
}

main();