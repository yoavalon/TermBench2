<?php

function decay_reward($reward, $factor, $threshold) {
    if ($reward < $threshold) {
        return 0;
    }
    return $reward * $factor;
}

function compute_reward($initial, $factor, $steps, $threshold) {
    $reward = $initial;
    for ($i = 0; $i < $steps; $i++) {
        $reward = decay_reward($reward, $factor, $threshold);
    }
    return $reward;
}

function main() {
    $initial_reward = 100;
    $decay_factor = 0.9;
    $steps = 10;
    $threshold = 10;
    $final_reward = compute_reward($initial_reward, $decay_factor, $steps, $threshold);
    echo $final_reward;
}

main();

?>