<?php

function optimize($positions, $velocities, $best_positions, $global_best, $w, $c1, $c2, $iterations, $count = 0) {
    if ($count == $iterations) {
        return $global_best;
    }
    $new_velocities = [];
    $new_positions = [];
    for ($i = 0; $i < count($positions); $i++) {
        $r1 = rand() / getrandmax();
        $r2 = rand() / getrandmax();
        $velocity = $w * $velocities[$i] + $c1 * $r1 * ($best_positions[$i] - $positions[$i]) + $c2 * $r2 * ($global_best - $positions[$i]);
        $position = $positions[$i] + $velocity;
        $new_velocities[] = $velocity;
        $new_positions[] = $position;
    }
    $fitnesses = array_map('fitness', $new_positions);
    for ($i = 0; $i < count($positions); $i++) {
        if ($fitnesses[$i] < fitness($best_positions[$i])) {
            $best_positions[$i] = $new_positions[$i];
        }
    }
    $min_fitness = min($fitnesses);
    if ($min_fitness < fitness($global_best)) {
        $global_best = $new_positions[array_search($min_fitness, $fitnesses)];
    }
    return optimize($new_positions, $new_velocities, $best_positions, $global_best, $w, $c1, $c2, $iterations, $count + 1);
}

function fitness($position) {
    return pow(sin($position), 2);
}

function main() {
    $positions = array_map(function() { return rand(-1000, 1000) / 100; }, range(0, 9));
    $velocities = array_fill(0, 10, 0);
    $best_positions = $positions;
    $global_best = min($positions, function($a, $b) { return fitness($a) <=> fitness($b); });
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $iterations = 30;
    $result = optimize($positions, $velocities, $best_positions, $global_best, $w, $c1, $c2, $iterations);
    echo $result;
}

main();