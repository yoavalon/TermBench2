<?php
function compute_decay($reward, $rate, $steps) {
    $decayed_rewards = array();
    for ($step = 0; $step < $steps; $step++) {
        $decayed_reward = $reward * pow($rate, $step);
        array_push($decayed_rewards, $decayed_reward);
        if ($decayed_reward < 0.01) {
            break;
        }
    }
    return $decayed_rewards;
}

function analyze_data($data) {
    $total = array_sum($data);
    $average = count($data) > 0 ? $total / count($data) : 0;
    return array($total, $average);
}

function main() {
    $initial_reward = 1.0;
    $decay_rate = 0.95;
    $max_steps = 1000;
    $rewards = compute_decay($initial_reward, $decay_rate, $max_steps);
    list($total, $average) = analyze_data($rewards);
    echo "Total Reward: $total, Average Reward: $average\n";
}

main();
?>