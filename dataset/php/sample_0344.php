<?php
function simulate_reward_decay() {
    $state = 0;
    $reward = 1.0;
    $discount = 0.99;
    while (true) {
        $state += 1;
        $reward *= $discount;
        echo 'State: ' . $state . ', Reward: ' . $reward . "\n";
    }
}
simulate_reward_decay();
?>