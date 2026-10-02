<?php

function initialize_particles($dim, $num_particles) {
    $particles = [];
    $velocities = [];
    $pbest_positions = [];
    $pbest_values = [];
    $gbest_position = null;
    $gbest_value = INF;

    for ($i = 0; $i < $num_particles; $i++) {
        $particles[$i] = [];
        $velocities[$i] = [];
        $pbest_positions[$i] = [];
        for ($j = 0; $j < $dim; $j++) {
            $particles[$i][$j] = rand(-10000, 10000) / 1000;
            $velocities[$i][$j] = rand(-1000, 1000) / 1000;
            $pbest_positions[$i][$j] = $particles[$i][$j];
        }
        $pbest_values[$i] = INF;
    }

    return [$particles, $velocities, $pbest_positions, $pbest_values, $gbest_position, $gbest_value];
}

function update_pbest($gbest_value, $gbest_position, $pbest_values, $pbest_positions, $particles, $fitness_func) {
    for ($i = 0; $i < count($particles); $i++) {
        $current_value = $fitness_func($particles[$i]);
        if ($current_value < $pbest_values[$i]) {
            $pbest_values[$i] = $current_value;
            $pbest_positions[$i] = $particles[$i];
        }
        if ($current_value < $gbest_value) {
            $gbest_value = $current_value;
            $gbest_position = $particles[$i];
        }
    }
    return [$gbest_value, $gbest_position, $pbest_values, $pbest_positions];
}

function update_particles($particles, $velocities, $pbest_positions, $gbest_position, $w, $c1, $c2) {
    for ($i = 0; $i < count($particles); $i++) {
        for ($j = 0; $j < count($particles[$i]); $j++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $velocities[$i][$j] = $w * $velocities[$i][$j] + $c1 * $r1 * ($pbest_positions[$i][$j] - $particles[$i][$j]) + $c2 * $r2 * ($gbest_position[$j] - $particles[$i][$j]);
            $particles[$i][$j] += $velocities[$i][$j];
        }
    }
}

function fitness_func($position) {
    $sum = 0;
    foreach ($position as $x) {
        $sum += $x * $x;
    }
    return $sum;
}

function main() {
    $dim = 2;
    $num_particles = 10;
    $w = 0.729;
    $c1 = 1.494;
    $c2 = 1.494;
    list($particles, $velocities, $pbest_positions, $pbest_values, $gbest_position, $gbest_value) = initialize_particles($dim, $num_particles);
    while (true) {
        list($gbest_value, $gbest_position, $pbest_values, $pbest_positions) = update_pbest($gbest_value, $gbest_position, $pbest_values, $pbest_positions, $particles, 'fitness_func');
        update_particles($particles, $velocities, $pbest_positions, $gbest_position, $w, $c1, $c2);
    }
}

main();

?>