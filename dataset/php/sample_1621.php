<?php
function update_state($state, $delta) {
    $new_state = [];
    foreach ($state as $key => $value) {
        $new_state[$key] = $value + $delta[$key];
    }
    return $new_state;
}

function simulate_system($initial_state, $deltas) {
    $current_state = $initial_state;
    while (true) {
        foreach ($deltas as $delta) {
            $current_state = update_state($current_state, $delta);
        }
    }
}

function main() {
    $initial_state = ['temperature' => 300, 'pressure' => 1];
    $deltas = [['temperature' => 10, 'pressure' => -0.5], ['temperature' => -5, 'pressure' => 0.25]];
    simulate_system($initial_state, $deltas);
}

main();
?>