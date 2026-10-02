<?php
function decay_reward($initial_value, $decay_rate, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $initial_value *= $decay_rate;
    }
    return $initial_value;
}

decay_reward(10.0, 0.9, 100);
?>