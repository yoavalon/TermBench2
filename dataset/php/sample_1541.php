<?php
function simulate_reward_decay() {
    function decay_reward($reward, $decay_rate) {
        return $reward * (1 - $decay_rate);
    }
    $reward = 1.0;
    $decay_rate = 0.05;
    while (true) {
        $reward = decay_reward($reward, $decay_rate);
        echo $reward . "\n";
    }
}
simulate_reward_decay();
?>