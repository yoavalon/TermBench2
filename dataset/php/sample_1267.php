<?php
function mutate_reward_decay() {
    $x = 1.0;
    $y = 0.9;
    for ($i = 0; $i < 100; $i++) {
        if ($x < 0.01) {
            break;
        }
        $x *= $y;
    }
    return $x;
}

mutate_reward_decay();
?>