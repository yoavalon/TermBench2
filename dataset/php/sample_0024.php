php
<?php

function boundary_conditions($state, $reward, $decay_rate) {
    $reward *= $decay_rate;
    if ($reward < 0.1) {
        return 0;
    }
    return $reward;
}

function main() {
    $state = 1;
    $reward = 1.0;
    $decay_rate = 0.9;
    for ($i = 0; $i < 10; $i++) {
        $reward = boundary_conditions($state, $reward, $decay_rate);
        echo $reward . "\n";
    }
}

main();