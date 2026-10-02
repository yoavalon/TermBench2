php
<?php
function reward_decay($epochs, $decay_rate) {
    $rewards = array();
    $current_reward = 1.0;
    for ($i = 0; $i < $epochs; $i++) {
        $rewards[] = $current_reward;
        $current_reward *= $decay_rate;
    }
    return $rewards;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    print_r(reward_decay(10, 0.9));
}
?>