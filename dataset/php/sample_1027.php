<?php

function update_velocity($pos, $vel, $best_pos, $global_best) {
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $r1 = 0.5;
    $r2 = 0.5;
    $new_vel = $w * $vel + $c1 * $r1 * ($best_pos - $pos) + $c2 * $r2 * ($global_best - $pos);
    return $new_vel;
}

function update_position($pos, $vel) {
    return $pos + $vel;
}

function optimize($func, $bounds, $n_particles = 30, $max_iter = 1000) {
    $particles = [];
    for ($i = 0; $i < $n_particles; $i++) {
        $particles[] = $bounds[0] + ($bounds[1] - $bounds[0]) * $i / $n_particles;
    }
    $velocities = array_fill(0, $n_particles, 0);
    $personal_best = $particles;
    $global_best = min($particles, function($a, $b) use ($func) {
        return $func($a) <=> $func($b);
    });

    function iterate($i, &$particles, &$velocities, &$personal_best, &$global_best, $func, $n_particles, $bounds) {
        for ($j = 0; $j < $n_particles; $j++) {
            $velocities[$j] = update_velocity($particles[$j], $velocities[$j], $personal_best[$j], $global_best);
            $particles[$j] = update_position($particles[$j], $velocities[$j]);
            if ($func($particles[$j]) < $func($personal_best[$j])) {
                $personal_best[$j] = $particles[$j];
            }
        }
        $global_best = min($personal_best, function($a, $b) use ($func) {
            return $func($a) <=> $func($b);
        });
        iterate($i + 1, $particles, $velocities, $personal_best, $global_best, $func, $n_particles, $bounds);
    }
    iterate(0, $particles, $velocities, $personal_best, $global_best, $func, $n_particles, $bounds);
}

function main() {
    $test_func = function($x) {
        return $x ** 2;
    };
    $bounds = [-100, 100];
    optimize($test_func, $bounds);
}

main();
?>