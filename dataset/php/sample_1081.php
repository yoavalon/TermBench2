<?php
function update_velocity(&$particles, &$velocities, &$pbest, &$gbest, $w, $c1, $c2) {
    for ($i = 0; $i < count($particles); $i++) {
        for ($j = 0; $j < count($particles[$i]); $j++) {
            $r1 = 0.5;
            $r2 = 0.5;
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
    while (true) {
        update_velocity($particles, $velocities, $pbest, $gbest, $w, $c1, $c2);
        update_position($particles, $velocities);
        for ($i = 0; $i < count($particles); $i++) {
            if ($pbest[$i][0] > $particles[$i][0]) {
                $pbest[$i] = $particles[$i];
            }
        }
        $min_particle = min(array_map(function($x) { return $x[0]; }, $particles));
        if ($gbest[0] > $min_particle) {
            $gbest = array_reduce($particles, function($carry, $item) {
                return $carry[0] < $item[0] ? $carry : $item;
            });
        }
    }
}

function main() {
    $particles = [[1, 2], [3, 4], [5, 6]];
    $velocities = [[0, 0], [0, 0], [0, 0]];
    $pbest = [[1, 2], [3, 4], [5, 6]];
    $gbest = min($particles, function($a, $b) { return $a[0] <=> $b[0]; });
    $w = 0.5;
    $c1 = 1.5;
    $c2 = 1.5;
    optimize($particles, $velocities, $pbest, $gbest, $w, $c1, $c2);
}

main();
?>