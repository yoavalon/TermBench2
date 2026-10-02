<?php
function decay_reward($alpha, $reward, $steps) {
    if ($steps == 0) {
        return 0;
    }
    return $alpha * $reward + decay_reward($alpha, $reward, $steps - 1);
}

$alpha = 0.9;
$reward = 10;
$steps = 5;
echo decay_reward($alpha, $reward, $steps);
?>