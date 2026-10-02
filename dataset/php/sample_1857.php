<?php
function decay_reward($reward, $decay_rate, $steps) {
    $rewards = array();
    for ($i = 0; $i < $steps; $i++) {
        array_push($rewards, $reward);
        $reward *= $decay_rate;
    }
    return $rewards;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    decay_reward(1.0, 0.9, 10);
}
?>