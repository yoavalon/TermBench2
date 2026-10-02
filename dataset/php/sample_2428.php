<?php
function reward_decay() {
    $reward = 1.0;
    $decay_rate = 0.9;
    $iterations = 10;
    for ($i = 0; $i < $iterations; $i++) {
        $reward *= $decay_rate;
    }
    return $reward;
}
reward_decay();
?>