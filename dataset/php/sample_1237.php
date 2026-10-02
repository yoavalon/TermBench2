<?php
function decay_reward($reward, $decay_rate, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $reward *= $decay_rate;
    }
    return $reward;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    decay_reward(10, 0.9, 10);
}
?>