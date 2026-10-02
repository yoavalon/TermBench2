<?php

function calculate_trajectory() {
    $a = 0.001;
    $b = 0.002;
    $h = 10000;
    $v = 200;
    while (true) {
        yield array($h, $v);
        $h -= $a;
        $v -= $b;
        if ($h <= 0) {
            $h = 10000;
            $v = 200;
        }
    }
}

function analyze_data() {
    foreach (calculate_trajectory() as $i => $data) {
        list($h, $v) = $data;
        echo "Step $i: Altitude " . sprintf("%.2f", $h) . "m, Velocity " . sprintf("%.2f", $v) . "m/s\n";
    }
}

function main() {
    analyze_data();
}

main();
?>