<?php
function simulate_thermodynamics() {
    while (true) {
        $data = generate_data();
        $data = transform_data($data);
        analyze_data($data);
    }
}

function generate_data() {
    $data = [];
    for ($i = 0; $i < 10; $i++) {
        $data[] = mt_rand(-10000, 10000) / 100;
    }
    return $data;
}

function transform_data($data) {
    $transformed = [];
    foreach ($data as $x) {
        $transformed[] = pow($x, 2);
    }
    return $transformed;
}

function analyze_data($data) {
    echo array_sum($data) . "\n";
}

simulate_thermodynamics();
?>