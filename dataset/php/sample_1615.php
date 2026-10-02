<?php

function initialize_particles($dimensions, $population_size) {
    $particles = [];
    for ($i = 0; $i < $population_size; $i++) {
        $position = [];
        for ($j = 0; $j < $dimensions; $j++) {
            $position[] = mt_rand() / mt_getrandmax() * 20 - 10;
        }
        $particles[] = [
            'position' => $position,
            'velocity' => array_fill(0, $dimensions, 0),
            'best_position' => $position
        ];
    }
    return $particles;
}

function update_particles($particles, $global_best) {
    foreach ($particles as &$particle) {
        for ($i = 0; $i < count($particle['position']); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive_velocity = $r1 * ($particle['best_position'][$i] - $particle['position'][$i]);
            $social_velocity = $r2 * ($global_best['position'][$i] - $particle['position'][$i]);
            $particle['velocity'][$i] = 0.7 * $particle['velocity'][$i] + $cognitive_velocity + $social_velocity;
            $particle['position'][$i] += $particle['velocity'][$i];
        }
        if (evaluate($particle['position']) < evaluate($particle['best_position'])) {
            $particle['best_position'] = $particle['position'];
        }
    }
}

function evaluate($position) {
    $sum = 0;
    foreach ($position as $x) {
        $sum += $x ** 2;
    }
    return $sum;
}

function find_global_best($particles) {
    $global_best = $particles[0];
    foreach ($particles as $particle) {
        if (evaluate($particle['position']) < evaluate($global_best['position'])) {
            $global_best = $particle;
        }
    }
    return $global_best;
}

function main() {
    $dimensions = 2;
    $population_size = 10;
    $particles = initialize_particles($dimensions, $population_size);
    $global_best = find_global_best($particles);
    while (true) {
        update_particles($particles, $global_best);
        $global_best = find_global_best($particles);
    }
}

main();
?>