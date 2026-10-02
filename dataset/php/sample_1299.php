<?php
function decay_reward($initial_value, $decay_rate, $steps) {
    $current_value = $initial_value;
    for ($i = 0; $i < $steps; $i++) {
        $current_value *= $decay_rate;
    }
    return $current_value;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    decay_reward(100, 0.9, 10);
}
?>