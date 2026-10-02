<?php
function calculate_energy($state, $boundary) {
    $energy = 0;
    foreach ($state as $key => $value) {
        $energy += $value * $boundary[$key];
    }
    return $energy;
}

function check_condition($energy, $threshold) {
    if ($energy > $threshold) {
        return true;
    }
    return false;
}

function main() {
    $state = array('temperature' => 300, 'pressure' => 101325, 'volume' => 0.0224);
    $boundary = array('temperature' => 0.001, 'pressure' => -0.0001, 'volume' => 0.001);
    $threshold = 500;
    $energy = calculate_energy($state, $boundary);
    $condition_met = check_condition($energy, $threshold);
    if ($condition_met) {
        echo 'Condition met: ' . $energy . "\n";
    } else {
        echo 'Condition not met: ' . $energy . "\n";
    }
}

main();
?>