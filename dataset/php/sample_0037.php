<?php

function decay_reward($alpha, $gamma, $epochs) {
    $rewards = array();
    $reward = 1.0;
    for ($i = 0; $i < $epochs; $i++) {
        $reward *= $gamma;
        array_push($rewards, $reward);
    }
    return $rewards;
}

decay_reward(0.1, 0.95, 10);

?>