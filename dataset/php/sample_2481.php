<?php
function calculate_discounted_rewards($rewards, $decay_rate, $steps) {
    $discounted_rewards = array();
    for ($i = 0; $i < $steps; $i++) {
        $discounted_rewards[$i] = $rewards[$i] * pow($decay_rate, $i);
    }
    return $discounted_rewards;
}

function main() {
    $rewards = array(100, 90, 80, 70, 60);
    $decay_rate = 0.9;
    $steps = 5;
    $result = calculate_discounted_rewards($rewards, $decay_rate, $steps);
    print_r($result);
}

main();
?>