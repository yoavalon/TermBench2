<?php

function update_state($state, $params) {
    foreach ($params as $key => $value) {
        $state[$key] += $value;
    }
    return $state;
}

function check_stability($state, $thresholds) {
    foreach ($thresholds as $key => $value) {
        if (abs($state[$key]) > $value) {
            return false;
        }
    }
    return true;
}

function simulate($state, $params, $thresholds, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $state = update_state($state, $params);
        if (!check_stability($state, $thresholds)) {
            return $state;
        }
    }
    return $state;
}

function main() {
    $state = ['temp' => 0, 'pressure' => 0];
    $params = ['temp' => 0.1, 'pressure' => -0.05];
    $thresholds = ['temp' => 1, 'pressure' => 0.5];
    $steps = 100;
    $final_state = simulate($state, $params, $thresholds, $steps);
    print_r($final_state);
}

main();

?>