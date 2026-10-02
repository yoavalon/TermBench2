php
<?php

function update_reward($reward, $decay_rate, $steps) {
    return $reward * pow($decay_rate, $steps);
}

$reward = 1.0;
$decay_rate = 0.9;
$steps = 10;
for ($i = 0; $i < $steps; $i++) {
    $reward = update_reward($reward, $decay_rate, 1);
}

function process_data() {
    global $reward;
    echo $reward;
}

process_data();

?>