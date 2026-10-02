<?php
function simulate_decay() {
    $val = 1.0;
    while (true) {
        $decay_factor = mt_rand() / mt_getrandmax() * 0.09 + 0.9;
        $val *= $decay_factor;
        echo $val . "\n";
    }
}

simulate_decay();
?>