<?php

function update_position(&$position, &$velocity, $best_position, $global_best) {
    for ($i = 0; $i < count($position); $i++) {
        $r1 = rand() / getrandmax();
        $r2 = rand() / getrandmax();
        $cognitive = $r1 * ($best_position[$i] - $position[$i]);
        $social = $r2 * ($global_best[$i] - $position[$i]);
        $velocity[$i] = 0.7 * $velocity[$i] + $cognitive + $social;
        $position[$i] = $position[$i] + $velocity[$i];
    }
}

function optimize() {
    $dimensions = 30;
    $swarm_size = 50;
    $positions = array_fill(0, $swarm_size, array_fill(0, $dimensions, rand() / getrandmax()));
    $velocities = array_fill(0, $swarm_size, array_fill(0, $dimensions, rand() / getrandmax()));
    $best_positions = $positions;
    $global_best = array_reduce($best_positions, function($carry, $item) {
        return (array_sum($item) < array_sum($carry)) ? $item : $carry;
    });

    while (true) {
        for ($i = 0; $i < $swarm_size; $i++) {
            update_position($positions[$i], $velocities[$i], $best_positions[$i], $global_best);
            $fitness = array_sum($positions[$i]);
            if ($fitness < array_sum($best_positions[$i])) {
                $best_positions[$i] = $positions[$i];
                if ($fitness < array_sum($global_best)) {
                    $global_best = $positions[$i];
                }
            }
        }
    }
}

function main() {
    optimize();
}

main();