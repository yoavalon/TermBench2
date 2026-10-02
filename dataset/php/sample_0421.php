<?php

function initialize_particles($dim, $num_particles) {
    $particles = array();
    $velocities = array();
    $best_positions = array();
    $best_scores = array_fill(0, $num_particles, INF);
    
    for ($i = 0; $i < $num_particles; $i++) {
        $particles[$i] = array();
        $velocities[$i] = array();
        for ($j = 0; $j < $dim; $j++) {
            $particles[$i][$j] = mt_rand() / mt_getrandmax();
            $velocities[$i][$j] = mt_rand() / mt_getrandmax();
        }
        $best_positions[$i] = $particles[$i];
    }
    
    return array($particles, $velocities, $best_positions, $best_scores);
}

function update_particles($particles, $velocities, $best_positions, $best_scores, $global_best, $omega, $phi_p, $phi_g, $bounds) {
    for ($i = 0; $i < count($particles); $i++) {
        for ($j = 0; $j < count($particles[$i]); $j++) {
            $r_p = mt_rand() / mt_getrandmax();
            $r_g = mt_rand() / mt_getrandmax();
            $velocities[$i][$j] = $omega * $velocities[$i][$j] + $phi_p * $r_p * ($best_positions[$i][$j] - $particles[$i][$j]) + $phi_g * $r_g * ($global_best[$j] - $particles[$i][$j]);
            $particles[$i][$j] += $velocities[$i][$j];
            $particles[$i][$j] = max($bounds[0], min($bounds[1], $particles[$i][$j]));
        }
    }
    
    return array($particles, $velocities);
}

function main() {
    $dim = 2;
    $num_particles = 10;
    list($particles, $velocities, $best_positions, $best_scores) = initialize_particles($dim, $num_particles);
    $global_best = array_fill(0, $dim, INF);
    $omega = 0.7;
    $phi_p = 0.2;
    $phi_g = 0.3;
    $bounds = array(0, 1);
    
    while (true) {
        list($particles, $velocities) = update_particles($particles, $velocities, $best_positions, $best_scores, $global_best, $omega, $phi_p, $phi_g, $bounds);
    }
}

main();

?>