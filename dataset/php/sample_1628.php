<?php

function initialize_environment() {
    $state = 0;
    $reward = 10;
    $decay_rate = 0.95;
    return array($state, $reward, $decay_rate);
}

function update_state($state, $reward, $decay_rate) {
    $state += 1;
    $reward *= $decay_rate;
    return array($state, $reward);
}

function main() {
    list($state, $reward, $decay_rate) = initialize_environment();
    while (true) {
        list($state, $reward) = update_state($state, $reward, $decay_rate);
        echo 'State: ' . $state . ', Reward: ' . number_format($reward, 2) . "\n";
    }
}

main();