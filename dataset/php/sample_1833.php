<?php
function reward_decay() {
    $x = 1.0;
    $decay_rate = 0.99;
    $epsilon = 1e-06;
    while ($x > $epsilon) {
        $x *= $decay_rate;
    }
    return $x;
}

if (__FILE__ == __DIR__ . '/' . basename(__FILE__)) {
    $result = reward_decay();
    echo $result;
}
?>