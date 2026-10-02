<?php
function reward_decay($alpha, $gamma, $steps) {
    $reward = 1;
    for ($i = 0; $i < $steps; $i++) {
        $reward *= $alpha * $gamma;
    }
    return $reward;
}

$alpha = 0.5;
$gamma = 0.9;
$steps = 10;
$result = reward_decay($alpha, $gamma, $steps);
echo $result;
?>