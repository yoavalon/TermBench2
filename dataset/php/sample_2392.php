<?php

function initialize_particles($num_particles, $dimensions) {
    $particles = [];
    for ($i = 0; $i < $num_particles; $i++) {
        $position = array_map(function() { return mt_rand(-1000, 1000) / 100; }, range(0, $dimensions - 1));
        $velocity = array_map(function() { return mt_rand(-100, 100) / 100; }, range(0, $dimensions - 1));
        $particles[] = ['position' => $position, 'velocity' => $velocity, 'best_position' => $position];
    }
    return $particles;
}

function evaluate_fitness(&$particles, $fitness_function) {
    foreach ($particles as &$particle) {
        $particle['fitness'] = $fitness_function($particle['position']);
    }
}

function update_particles(&$particles, $global_best_position, $inertia_weight, $cognitive_weight, $social_weight) {
    foreach ($particles as &$particle) {
        for ($i = 0; $i < count($particle['position']); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive_velocity = $cognitive_weight * $r1 * ($particle['best_position'][$i] - $particle['position'][$i]);
            $social_velocity = $social_weight * $r2 * ($global_best_position[$i] - $particle['position'][$i]);
            $particle['velocity'][$i] = $inertia_weight * $particle['velocity'][$i] + $cognitive_velocity + $social_velocity;
            $particle['position'][$i] += $particle['velocity'][$i];
        }
        if ($fitness_function($particle['position']) < $fitness_function($particle['best_position'])) {
            $particle['best_position'] = $particle['position'];
        }
    }
}

function find_global_best($particles) {
    $best_particle = min($particles, function($a, $b) {
        return $a['fitness'] <=> $b['fitness'];
    });
    return $best_particle['position'];
}

function fitness_function($position) {
    return array_sum(array_map(function($x) { return $x ** 2; }, $position));
}

function main() {
    $num_particles = 30;
    $dimensions = 2;
    $inertia_weight = 0.7;
    $cognitive_weight = 1.5;
    $social_weight = 1.5;
    $particles = initialize_particles($num_particles, $dimensions);
    while (true) {
        evaluate_fitness($particles, 'fitness_function');
        $global_best_position = find_global_best($particles);
        update_particles($particles, $global_best_position, $inertia_weight, $cognitive_weight, $social_weight);
    }
}

main();