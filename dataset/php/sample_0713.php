<?php
function reward_decay($current, $rate, $threshold) {
    if ($current <= $threshold) {
        return $current;
    }
    return reward_decay($current * $rate, $rate, $threshold);
}

function calculate_discounted_rewards($initial, $rate, $threshold) {
    $rewards = array();
    while ($initial > $threshold) {
        $rewards[] = $initial;
        $initial = $initial * $rate;
    }
    $rewards[] = $initial;
    return $rewards;
}

function main() {
    $initial = 100;
    $rate = 0.9;
    $threshold = 10;
    $result = calculate_discounted_rewards($initial, $rate, $threshold);
    print_r($result);
}

main();
?>