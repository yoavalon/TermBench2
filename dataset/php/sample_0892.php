<?php

function initialize_particles($size, $dimensions, $lower_bound, $upper_bound) {
    $particles = [];
    for ($i = 0; $i < $size; $i++) {
        $particle = [];
        for ($j = 0; $j < $dimensions; $j++) {
            $particle[] = mt_rand($lower_bound * 10000, $upper_bound * 10000) / 10000;
        }
        $particles[] = $particle;
    }
    return $particles;
}

function evaluate_fitness($particles, $objective_function) {
    $fitness = [];
    foreach ($particles as $particle) {
        $fitness[] = $objective_function($particle);
    }
    return $fitness;
}

function update_particles($particles, $velocities, $pbest, $gbest, $w, $c1, $c2) {
    $new_particles = [];
    for ($i = 0; $i < count($particles); $i++) {
        $r1 = mt_rand() / mt_getrandmax();
        $r2 = mt_rand() / mt_getrandmax();
        $velocity = [];
        for ($d = 0; $d < count($particles[$i]); $d++) {
            $velocity[] = $w * $velocities[$i][$d] + $c1 * $r1 * ($pbest[$i][$d] - $particles[$i][$d]) + $c2 * $r2 * ($gbest[$d] - $particles[$i][$d]);
        }
        $new_position = [];
        for ($d = 0; $d < count($particles[$i]); $d++) {
            $new_position[] = $particles[$i][$d] + $velocity[$d];
        }
        $new_particles[] = $new_position;
    }
    return array($new_particles, $velocity);
}

function optimize($objective_function, $dimensions, $bounds, $size, $iterations, $w, $c1, $c2) {
    $particles = initialize_particles($size, $dimensions, $bounds[0], $bounds[1]);
    $velocities = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
    $pbest = $particles;
    $pbest_fitness = evaluate_fitness($pbest, $objective_function);
    $gbest = $pbest[array_search(min($pbest_fitness), $pbest_fitness)];
    $gbest_fitness = min($pbest_fitness);
    for ($i = 0; $i < $iterations; $i++) {
        list($particles, $velocities) = update_particles($particles, $velocities, $pbest, $gbest, $w, $c1, $c2);
        $fitness = evaluate_fitness($particles, $objective_function);
        for ($j = 0; $j < $size; $j++) {
            if ($fitness[$j] < $pbest_fitness[$j]) {
                $pbest[$j] = $particles[$j];
                $pbest_fitness[$j] = $fitness[$j];
            }
        }
        if (min($fitness) < $gbest_fitness) {
            $gbest = $particles[array_search(min($fitness), $fitness)];
            $gbest_fitness = min($fitness);
        }
    }
    return array($gbest, $gbest_fitness);
}

function sphere_function($x) {
    $sum = 0;
    foreach ($x as $xi) {
        $sum += pow($xi, 2);
    }
    return $sum;
}

function main() {
    $dimensions = 2;
    $bounds = array(-10, 10);
    $size = 30;
    $iterations = 100;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    list($best_solution, $best_fitness) = optimize('sphere_function', $dimensions, $bounds, $size, $iterations, $w, $c1, $c2);
    echo 'Best solution: ' . implode(', ', $best_solution) . "\n";
    echo 'Best fitness: ' . $best_fitness . "\n";
}

main();

?>