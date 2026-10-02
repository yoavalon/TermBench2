<?php

function fitness_function($x) {
    return pow($x, 2);
}

function update_position($position, $velocity, $w, $c1, $c2, $pbest, $gbest) {
    $r1 = rand() / getrandmax();
    $r2 = rand() / getrandmax();
    $velocity = $w * $velocity + $c1 * $r1 * ($pbest - $position) + $c2 * $r2 * ($gbest - $position);
    $position = $position + $velocity;
    return array($position, $velocity);
}

function optimize($iterations, $w, $c1, $c2, $bounds) {
    $particles = array();
    for ($i = 0; $i < 30; $i++) {
        $particles[] = $bounds[0] + mt_rand() / mt_getrandmax() * ($bounds[1] - $bounds[0]);
    }
    $velocities = array_fill(0, 30, 0);
    $pbests = $particles;
    $gbest = min($particles, function($a, $b) {
        return fitness_function($a) <=> fitness_function($b);
    });
    for ($i = 0; $i < $iterations; $i++) {
        for ($j = 0; $j < count($particles); $j++) {
            list($particles[$j], $velocities[$j]) = update_position($particles[$j], $velocities[$j], $w, $c1, $c2, $pbests[$j], $gbest);
            if (fitness_function($particles[$j]) < fitness_function($pbests[$j])) {
                $pbests[$j] = $particles[$j];
            }
        }
        $gbest = min($particles, function($a, $b) {
            return fitness_function($a) <=> fitness_function($b);
        });
    }
    return $gbest;
}

function main() {
    $iterations = 100;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $bounds = array(-10, 10);
    $result = optimize($iterations, $w, $c1, $c2, $bounds);
    echo $result;
}

main();

?>