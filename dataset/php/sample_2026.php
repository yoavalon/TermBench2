<?php

function initialize_particles($size, $dimensions) {
    $particles = [];
    for ($i = 0; $i < $size; $i++) {
        $position = array_fill(0, $dimensions, mt_rand() / mt_getrandmax() * 20 - 10);
        $velocity = array_fill(0, $dimensions, mt_rand() / mt_getrandmax() * 2 - 1);
        $pbest_position = $position;
        $pbest_value = PHP_FLOAT_MAX;
        $particles[] = ['position' => $position, 'velocity' => $velocity, 'pbest_position' => $pbest_position, 'pbest_value' => $pbest_value];
    }
    return $particles;
}

function update_velocity(&$particles, $gbest_position, $w = 0.7, $c1 = 1.5, $c2 = 1.5) {
    foreach ($particles as &$particle) {
        for ($i = 0; $i < count($particle['position']); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($particle['pbest_position'][$i] - $particle['position'][$i]);
            $social = $c2 * $r2 * ($gbest_position[$i] - $particle['position'][$i]);
            $particle['velocity'][$i] = $w * $particle['velocity'][$i] + $cognitive + $social;
        }
    }
}

function update_position(&$particles, $bounds) {
    foreach ($particles as &$particle) {
        for ($i = 0; $i < count($particle['position']); $i++) {
            $particle['position'][$i] += $particle['velocity'][$i];
            $particle['position'][$i] = max($bounds[0], min($particle['position'][$i], $bounds[1]));
        }
    }
}

function evaluate(&$particles, $objective_function) {
    foreach ($particles as &$particle) {
        $value = $objective_function($particle['position']);
        if ($value < $particle['pbest_value']) {
            $particle['pbest_value'] = $value;
            $particle['pbest_position'] = $particle['position'];
        }
    }
}

function find_gbest($particles) {
    $gbest_value = PHP_FLOAT_MAX;
    $gbest_position = null;
    foreach ($particles as $particle) {
        if ($particle['pbest_value'] < $gbest_value) {
            $gbest_value = $particle['pbest_value'];
            $gbest_position = $particle['pbest_position'];
        }
    }
    return $gbest_position;
}

function optimize($objective_function, $dimensions, $size, $iterations, $bounds) {
    $particles = initialize_particles($size, $dimensions);
    $gbest_position = find_gbest($particles);
    for ($t = 0; $t < $iterations; $t++) {
        update_velocity($particles, $gbest_position);
        update_position($particles, $bounds);
        evaluate($particles, $objective_function);
        $gbest_position = find_gbest($particles);
    }
    return $gbest_position;
}

function main() {
    function sphere_function($x) {
        $sum = 0;
        foreach ($x as $xi) {
            $sum += pow($xi, 2);
        }
        return $sum;
    }
    $dimensions = 30;
    $size = 30;
    $iterations = 100;
    $bounds = [-10, 10];
    $result = optimize('sphere_function', $dimensions, $size, $iterations, $bounds);
    print_r($result);
}

main();
?>