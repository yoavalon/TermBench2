<?php

function initialize_particles($num_particles, $num_dimensions) {
    $particles = [];
    for ($i = 0; $i < $num_particles; $i++) {
        $position = [];
        $velocity = [];
        for ($j = 0; $j < $num_dimensions; $j++) {
            $position[] = mt_rand() / mt_getrandmax() * 20 - 10;
            $velocity[] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        $particles[] = ['position' => $position, 'velocity' => $velocity, 'best_position' => $position];
    }
    return $particles;
}

function update_velocity(&$particles, $global_best, $w, $c1, $c2) {
    foreach ($particles as &$particle) {
        $r1 = mt_rand() / mt_getrandmax();
        $r2 = mt_rand() / mt_getrandmax();
        for ($i = 0; $i < count($particle['position']); $i++) {
            $cognitive_velocity = $c1 * $r1 * ($particle['best_position'][$i] - $particle['position'][$i]);
            $social_velocity = $c2 * $r2 * ($global_best['position'][$i] - $particle['position'][$i]);
            $particle['velocity'][$i] = $w * $particle['velocity'][$i] + $cognitive_velocity + $social_velocity;
        }
    }
}

function update_position(&$particles) {
    foreach ($particles as &$particle) {
        for ($i = 0; $i < count($particle['position']); $i++) {
            $particle['position'][$i] += $particle['velocity'][$i];
        }
    }
}

function evaluate_fitness($particles, $fitness_function) {
    $best_particle = null;
    $best_fitness = PHP_FLOAT_MAX;
    foreach ($particles as $particle) {
        $fitness = $fitness_function($particle['position']);
        if ($fitness < $best_fitness) {
            $best_fitness = $fitness;
            $best_particle = $particle;
            if ($fitness < $fitness_function($particle['best_position'])) {
                $particle['best_position'] = $particle['position'];
            }
        }
    }
    return $best_particle;
}

function main() {
    $num_particles = 20;
    $num_dimensions = 2;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $max_iterations = 100;

    $fitness_function = function($position) {
        return array_sum(array_map(function($x) { return $x ** 2; }, $position));
    };

    $particles = initialize_particles($num_particles, $num_dimensions);
    $global_best = evaluate_fitness($particles, $fitness_function);
    for ($i = 0; $i < $max_iterations; $i++) {
        update_velocity($particles, $global_best, $w, $c1, $c2);
        update_position($particles);
        $global_best = evaluate_fitness($particles, $fitness_function);
    }
    echo 'Best position found: ' . implode(', ', $global_best['best_position']) . "\n";
    echo 'Fitness value: ' . $fitness_function($global_best['best_position']) . "\n";
}

main();

?>