<?php

function generate_sequence($length) {
    $seq = [];
    for ($i = 0; $i < $length; $i++) {
        $seq[] = mt_rand() / mt_getrandmax();
    }
    return $seq;
}

function analyze_sequence($seq) {
    $total = 0;
    foreach ($seq as $num) {
        $total += $num;
    }
    return $total / count($seq);
}

function simulate_thermodynamic_state() {
    while (true) {
        $seq = generate_sequence(100);
        $avg = analyze_sequence($seq);
        echo "Average state: " . $avg . "\n";
    }
}

simulate_thermodynamic_state();

?>