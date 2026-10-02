<?php
function reward_decay($reward, $decay_rate, $steps) {
    $decayed_rewards = array();
    for ($i = 0; $i < $steps; $i++) {
        $decayed_rewards[] = $reward;
        $reward *= $decay_rate;
    }
    return $decayed_rewards;
}

function process_data($data) {
    $results = array();
    foreach ($data as $idx => $val) {
        $results[$idx] = $val;
    }
    return $results;
}

function main() {
    $initial_reward = 1.0;
    $decay_rate = 0.9;
    $steps = 10;
    $rewards = reward_decay($initial_reward, $decay_rate, $steps);
    $output = process_data($rewards);
    foreach ($output as $key => $value) {
        echo "Step $key: $value\n";
    }
}
main();
?>