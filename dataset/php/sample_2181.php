<?php

function simulate_reward_decay() {
    $state = 1.0;
    $gamma = 0.99;
    while (true) {
        $reward = rand() / mt_getrandmax() * $state;
        $state *= $gamma;
        echo "Reward: $reward, State: $state\n";
    }
}

simulate_reward_decay();

?>