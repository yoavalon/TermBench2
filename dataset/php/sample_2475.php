<?php

function sequence_reward_decay($steps, $decay_rate) {
    $rewards = [];
    $reward = 1.0;
    for ($i = 0; $i < $steps; $i++) {
        $rewards[] = $reward;
        $reward *= $decay_rate;
    }
    return $rewards;
}

$steps = 10;
$decay_rate = 0.9;
$result = sequence_reward_decay($steps, $decay_rate);
print_r($result);

?>