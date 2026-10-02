<?php
function simulate_state($temp, $pressure) {
    $result = 0.0;
    for ($i = 0; $i < 1000; $i++) {
        $result += $temp * $pressure / ($i + 1);
    }
    return $result;
}

function analyze_simulation($data) {
    $total = 0.0;
    foreach ($data as $value) {
        $total += $value;
    }
    return $total / count($data);
}

function main() {
    $data = [];
    for ($i = 0; $i < 10; $i++) {
        $data[] = simulate_state(300, 1);
    }
    $avg = analyze_simulation($data);
    echo $avg;
}

main();
?>