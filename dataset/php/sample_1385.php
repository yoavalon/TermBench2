<?php
function simulate_temperature_change($initial_temp, $rate, $steps) {
    $temperatures = array($initial_temp);
    for ($i = 0; $i < $steps; $i++) {
        $new_temp = $temperatures[count($temperatures) - 1] + $rate;
        $temperatures[] = $new_temp;
    }
    return $temperatures;
}

function analyze_data($data) {
    $max_temp = max($data);
    $min_temp = min($data);
    return array($max_temp, $min_temp);
}

function main() {
    $data = simulate_temperature_change(20, 2, 10);
    list($max_temp, $min_temp) = analyze_data($data);
    echo $max_temp . " " . $min_temp;
}
main();
?>