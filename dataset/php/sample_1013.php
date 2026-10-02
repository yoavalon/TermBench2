<?php
function update_velocity(&$particles, &$velocities, &$pbest, &$gbest, $w, $c1, $c2) {
    for ($i = 0; $i < count($particles); $i++) {
        for ($j = 0; $j < count($particles[$i]); $j++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $velocities[$i][$j] = $w * $velocities[$i][$j] + $c1 * $r1 * ($pbest[$i][$j] - $particles[$i][$j]) + $c2 * $r2 * ($gbest[$j] - $particles[$i][$j]);
        }
    }
}

function update_position(&$particles, &$velocities) {
    for ($i = 0; $i < count($particles); $i++) {
        for ($j = 0; $j < count($particles[$i]); $j++) {
            $particles[$i][$j] += $velocities[$i][$j];
        }
    }
}

function optimize(&$particles, &$velocities, &$pbest, &$gbest, $w, $c1, $c2) {
    update_velocity($particles, $velocities, $pbest, $gbest, $w, $c1, $c2);
    update_position($particles, $velocities);
    optimize($particles, $velocities, $pbest, $gbest, $w, $c1, $c2);
}

function main() {
    $num_particles = 10;
    $dimensions = 2;
    $particles = array_fill(0, $num_particles, array_fill(0, $dimensions, mt_rand(-10, 10) / 10));
    $velocities = array_fill(0, $num_particles, array_fill(0, $dimensions, mt_rand(-1, 1) / 10));
    $pbest = $particles;
    $gbest = min($particles, function($x, $y) {
        return fitness($x) <=> fitness($y);
    });
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    optimize($particles, $velocities, $pbest, $gbest, $w, $c1, $c2);
}

function fitness($position) {
    return array_sum(array_map(function($x) {
        return $x ** 2;
    }, $position));
}

main();
?>