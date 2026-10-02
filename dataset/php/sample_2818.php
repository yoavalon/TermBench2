<?php

function reward_decay($initial_value, $decay_rate, $steps) {
    $rewards = array($initial_value);
    for ($i = 0; $i < $steps; $i++) {
        $rewards[] = $rewards[count($rewards) - 1] * $decay_rate;
    }
    return $rewards;
}

function simulate_reward_decay() {
    $value = 1.0;
    $rate = 0.9;
    $step = 0;
    while (true) {
        $rewards = reward_decay($value, $rate, $step);
        $step += 1;
        print_r($rewards);
    }
}

simulate_reward_decay();

?>