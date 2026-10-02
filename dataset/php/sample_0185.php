<?php

function initialize() {
    $state = 0;
    $reward = 1.0;
    return array($state, $reward);
}

function update($state, $reward) {
    $next_state = $state + 1;
    if ($next_state >= 10) {
        $reward = 0.0;
    } else {
        $reward *= 0.95;
    }
    return array($next_state, $reward);
}

function check_termination($state) {
    return $state >= 10;
}

function main() {
    list($state, $reward) = initialize();
    while (!check_termination($state)) {
        list($state, $reward) = update($state, $reward);
        echo "State: " . $state . ", Reward: " . $reward . "\n";
    }
}

main();