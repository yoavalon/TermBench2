<?php
function simulate_decay($steps) {
    $reward = 1.0;
    $decay_rate = 0.99;
    for ($i = 0; $i < $steps; $i++) {
        $reward *= $decay_rate;
    }
    return $reward;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = simulate_decay(1000);
    echo $result;
}
?>