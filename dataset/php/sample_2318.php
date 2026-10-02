<?php

function initialize_particles($dimensions, $count) {
    $particles = [];
    for ($i = 0; $i < $count; $i++) {
        $position = array_fill(0, $dimensions, rand(-10000, 10000) / 1000);
        $velocity = array_fill(0, $dimensions, rand(-1000, 1000) / 1000);
        $particles[] = ['position' => $position, 'velocity' => $velocity, 'best_position' => $position];
    }
    return $particles;
}

function evaluate_fitness($particles, $objective_function) {
    foreach ($particles as &$particle) {
        $particle['fitness'] = $objective_function($particle['position']);
    }
}

function update_particles($particles, $global_best, $inertia_weight, $cognitive_weight, $social_weight) {
    foreach ($particles as &$particle) {
        for ($i = 0; $i < count($particle['position']); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive_velocity = $cognitive_weight * $r1 * ($particle['best_position'][$i] - $particle['position'][$i]);
            $social_velocity = $social_weight * $r2 * ($global_best['position'][$i] - $particle['position'][$i]);
            $particle['velocity'][$i] = $inertia_weight * $particle['velocity'][$i] + $cognitive_velocity + $social_velocity;
            $particle['position'][$i] += $particle['velocity'][$i];
        }
        $particle['best_position'] = ($particle['fitness'] < $particle['best_position']['fitness']) ? $particle['position'] : $particle['best_position'];
    }
}

function find_global_best($particles) {
    $global_best = $particles[0];
    foreach ($particles as $particle) {
        if ($particle['fitness'] < $global_best['fitness']) {
            $global_best = $particle;
        }
    }
    return $global_best;
}

function objective_function($position) {
    $sum = 0;
    foreach ($position as $x) {
        $sum += $x ** 2;
    }
    return $sum;
}

function main() {
    $dimensions = 2;
    $particle_count = 30;
    $inertia_weight = 0.7;
    $cognitive_weight = 1.5;
    $social_weight = 1.5;
    $particles = initialize_particles($dimensions, $particle_count);
    while (true) {
        evaluate_fitness($particles, 'objective_function');
        $global_best = find_global_best($particles);
        update_particles($particles, $global_best, $inertia_weight, $cognitive_weight, $social_weight);
    }
}

main();

?>