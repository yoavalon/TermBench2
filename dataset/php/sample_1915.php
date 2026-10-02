php
<?php

function simulate_pressure($a, $b, $c) {
    return ($a + $b + $c) / 3.0;
}

function calculate_temperature($pressure, $constant) {
    return $pressure * $constant;
}

function analyze_system($a, $b, $c, $constant) {
    $pressure = simulate_pressure($a, $b, $c);
    $temperature = calculate_temperature($pressure, $constant);
    return $temperature;
}

function main() {
    $a = 100.0;
    $b = 200.0;
    $c = 150.0;
    $constant = 0.5;
    $result = analyze_system($a, $b, $c, $constant);
    echo $result;
}

main();

?>