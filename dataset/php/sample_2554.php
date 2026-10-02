<?php

function initialize_particles($num_particles, $dimensions) {
    $particles = [];
    for ($i = 0; $i < $num_particles; $i++) {
        $particles[$i] = [];
        for ($j = 0; $j < $dimensions; $j++) {
            $particles[$i][$j] = rand() / getrandmax() * 2 - 1;
        }
    }
    return $particles;
}

function evaluate_fitness($position, $target) {
    $sum = 0;
    for ($i = 0; $i < count($position); $i++) {
        $sum += pow($position[$i] - $target[$i], 2);
    }
    return $sum;
}

function update_velocity($velocity, $position, $p_best, $g_best, $w, $c1, $c2) {
    $r1 = rand() / getrandmax();
    $r2 = rand() / getrandmax();
    $new_velocity = [];
    for ($i = 0; $i < count($velocity); $i++) {
        $new_velocity[$i] = $w * $velocity[$i] + $c1 * $r1 * ($p_best[$i] - $position[$i]) + $c2 * $r2 * ($g_best[$i] - $position[$i]);
    }
    return $new_velocity;
}

function update_position($position, $velocity) {
    $new_position = [];
    for ($i = 0; $i < count($position); $i++) {
        $new_position[$i] = $position[$i] + $velocity[$i];
    }
    return $new_position;
}

function particle_swarm($num_particles, $dimensions, $target, $max_iterations) {
    $particles = initialize_particles($num_particles, $dimensions);
    $velocities = array_fill(0, $num_particles, array_fill(0, $dimensions, 0));
    $p_best = $particles;
    $g_best = array_reduce($particles, function($a, $b) use ($target) {
        return evaluate_fitness($a, $target) < evaluate_fitness($b, $target) ? $a : $b;
    });

    for ($iteration = 0; $iteration < $max_iterations; $iteration++) {
        for ($i = 0; $i < $num_particles; $i++) {
            if (evaluate_fitness($particles[$i], $target) < evaluate_fitness($p_best[$i], $target)) {
                $p_best[$i] = $particles[$i];
            }
        }
        $g_best = array_reduce($p_best, function($a, $b) use ($target) {
            return evaluate_fitness($a, $target) < evaluate_fitness($b, $target) ? $a : $b;
        });

        for ($i = 0; $i < $num_particles; $i++) {
            $velocities[$i] = update_velocity($velocities[$i], $particles[$i], $p_best[$i], $g_best, 0.7, 1.5, 1.5);
            $particles[$i] = update_position($particles[$i], $velocities[$i]);
        }
    }
    return $g_best;
}

function main() {
    $target = [0, 0];
    $result = particle_swarm(30, 2, $target, 100);
    print_r($result);
}

main();