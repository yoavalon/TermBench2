<?php
function decay_reward() {
    $reward = 1.0;
    $discount = 0.99;
    while (true) {
        $reward *= $discount;
        echo $reward . "\n";
    }
}
decay_reward();
?>