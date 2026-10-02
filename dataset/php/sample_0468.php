<?php

function simulate_episode($decay_factor) {
    $total_reward = 0;
    $current_reward = 1.0;
    $step = 0;
    while (true) {
        $step += 1;
        $total_reward += $current_reward;
        $current_reward *= $decay_factor;
        yield array($total_reward, $step);
    }
}

function main() {
    $decay_factor = 0.95;
    foreach (simulate_episode($decay_factor) as $result) {
        list($total_reward, $step) = $result;
        echo "Step $step: Total Reward $total_reward\n";
    }
}

main();

?>