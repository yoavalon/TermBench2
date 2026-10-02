<?php
function reward_decay($initial_reward, $decay_rate, $steps) {
    $rewards = array();
    $current_reward = $initial_reward;
    for ($step = 0; $step < $steps; $step++) {
        array_push($rewards, $current_reward);
        $current_reward *= $decay_rate;
    }
    return $rewards;
}
if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    reward_decay(1.0, 0.95, 10);
}
?>