<?php

function simulate_reward_decay($steps, $decay_rate) {
    $rewards = [rand() / mt_getrandmax()];
    for ($i = 1; $i < $steps; $i++) {
        $rewards[] = $rewards[$i - 1] * $decay_rate;
    }
    return $rewards;
}

function main() {
    $steps = 10;
    $decay_rate = 0.9;
    $result = simulate_reward_decay($steps, $decay_rate);
    print_r($result);
}

main();

?>