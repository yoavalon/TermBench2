<?php
function optimize($positions, $velocities, $personal_best, $global_best, $iteration, $max_iterations) {
    if ($iteration >= $max_iterations) {
        return $global_best;
    }
    $new_positions = [];
    $new_velocities = [];
    for ($i = 0; $i < count($positions); $i++) {
        $r1 = rand() / getrandmax();
        $r2 = rand() / getrandmax();
        $new_velocity = $velocities[$i] + 2 * $r1 * ($personal_best[$i] - $positions[$i]) + 2 * $r2 * ($global_best - $positions[$i]);
        $new_position = $positions[$i] + $new_velocity;
        $new_positions[] = $new_position;
        $new_velocities[] = $new_velocity;
    }
    $new_global_best = min($new_positions, function($x) {
        return fitness($x);
    });
    return optimize($new_positions, $new_velocities, $personal_best, $new_global_best, $iteration + 1, $max_iterations);
}

function fitness($x) {
    return $x ** 2;
}

function main() {
    $positions = array_map(function() {
        return rand(-1000, 1000) / 100;
    }, range(0, 9));
    $velocities = array_fill(0, 10, 0.0);
    $personal_best = $positions;
    $global_best = min($positions, function($x) {
        return fitness($x);
    });
    optimize($positions, $velocities, $personal_best, $global_best, 0, 100);
}

main();
?>