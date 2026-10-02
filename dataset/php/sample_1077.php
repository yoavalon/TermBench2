<?php

function update_velocity($p, $g, $v, $w, $c1, $c2) {
    $r1 = rand() / getrandmax();
    $r2 = rand() / getrandmax();
    return $w * $v + $c1 * $r1 * ($p - $g) + $c2 * $r2 * ($p - $p);
}

function update_position($p, $v) {
    return $p + $v;
}

function optimize($particles, $velocities, $best_positions, $global_best, $w, $c1, $c2) {
    $new_particles = [];
    $new_velocities = [];
    $new_best_positions = [];
    for ($i = 0; $i < count($particles); $i++) {
        $v = update_velocity($particles[$i], $global_best, $velocities[$i], $w, $c1, $c2);
        $p = update_position($particles[$i], $v);
        $new_particles[] = $p;
        $new_velocities[] = $v;
        if ($p < $best_positions[$i]) {
            $new_best_positions[] = $p;
        } else {
            $new_best_positions[] = $best_positions[$i];
        }
    }
    return [$new_particles, $new_velocities, $new_best_positions];
}

function swarm() {
    $particles = array_map(function() { return rand() / getrandmax(); }, range(0, 9));
    $velocities = array_map(function() { return rand() / getrandmax(); }, range(0, 9));
    $best_positions = $particles;
    $global_best = min($particles);
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    while (true) {
        list($particles, $velocities, $best_positions) = optimize($particles, $velocities, $best_positions, $global_best, $w, $c1, $c2);
        $global_best = min($best_positions);
    }
}

swarm();

?>