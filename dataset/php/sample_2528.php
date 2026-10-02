<?php
function decay_reward($reward, $decay_rate, $steps) {
    $decayed_rewards = array();
    for ($step = 0; $step < $steps; $step++) {
        $decayed_rewards[] = $reward * pow($decay_rate, $step);
    }
    return $decayed_rewards;
}

function calculate_final_reward($initial_reward, $decay_rate, $steps) {
    $rewards = decay_reward($initial_reward, $decay_rate, $steps);
    return array_sum($rewards);
}

function main() {
    $initial = 100;
    $rate = 0.9;
    $steps = 10;
    $final_reward = calculate_final_reward($initial, $rate, $steps);
    echo $final_reward;
}

main();
?>