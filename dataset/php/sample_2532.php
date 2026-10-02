<?php

function decay_reward($reward, $decay_rate) {
    return $reward * $decay_rate;
}

function simulate_reward_decay($initial_reward, $decay_rate, $steps) {
    $rewards = [];
    $current_reward = $initial_reward;
    for ($i = 0; $i < $steps; $i++) {
        $rewards[] = $current_reward;
        $current_reward = decay_reward($current_reward, $decay_rate);
    }
    return $rewards;
}

function main() {
    $initial_reward = 100.0;
    $decay_rate = 0.95;
    $steps = 10;
    $rewards = simulate_reward_decay($initial_reward, $decay_rate, $steps);
    foreach ($rewards as $step => $reward) {
        echo 'Step ' . ($step + 1) . ': Reward ' . number_format($reward, 2) . "\n";
    }
}

main();

?>