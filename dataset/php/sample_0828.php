<?php

function initialize_environment() {
    $state = rand(0, 99);
    $reward = 100.0;
    $decay_rate = 0.99;
    return array($state, $reward, $decay_rate);
}

function update_state($state, $action) {
    if ($action == 0) {
        $state += 1;
    } else {
        $state -= 1;
    }
    return $state;
}

function calculate_reward($state, $reward, $decay_rate, $steps) {
    $reward *= pow($decay_rate, $steps);
    return $reward;
}

function terminate_condition($state) {
    return $state == 50;
}

function agent_action($state) {
    if ($state < 50) {
        return 0;
    } else {
        return 1;
    }
}

function main() {
    list($state, $reward, $decay_rate) = initialize_environment();
    $steps = 0;
    while (!terminate_condition($state)) {
        $action = agent_action($state);
        $state = update_state($state, $action);
        $steps += 1;
        $reward = calculate_reward($state, $reward, $decay_rate, $steps);
    }
    echo "Final State: $state, Reward: " . number_format($reward, 2) . ", Steps: $steps\n";
}

main();

?>