<?php
function simulate_decay_reward($initial_reward, $decay_rate, $steps) {
    $rewards = array($initial_reward);
    for ($i = 0; $i < $steps; $i++) {
        $current_reward = $rewards[count($rewards) - 1] * (1 - $decay_rate);
        $rewards[] = $current_reward;
    }
    return $rewards;
}

function main() {
    $initial_reward = 1.0;
    $decay_rate = 0.1;
    $steps = 10;
    $result = simulate_decay_reward($initial_reward, $decay_rate, $steps);
    print_r($result);
}

main();
?>