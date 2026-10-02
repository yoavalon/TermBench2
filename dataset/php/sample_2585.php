<?php
function reward_decay($init_val, $decay_rate, $steps) {
    $rewards = array();
    $current_val = $init_val;
    for ($i = 0; $i < $steps; $i++) {
        array_push($rewards, $current_val);
        $current_val *= $decay_rate;
    }
    return $rewards;
}

function analyze_rewards($rewards) {
    $total = array_sum($rewards);
    $avg = $total / count($rewards);
    return array($total, $avg);
}

function main() {
    $initial_value = 1.0;
    $decay_rate = 0.9;
    $number_of_steps = 10;
    $sequence = reward_decay($initial_value, $decay_rate, $number_of_steps);
    list($total, $average) = analyze_rewards($sequence);
    echo "Total: $total, Average: $average\n";
}

main();
?>