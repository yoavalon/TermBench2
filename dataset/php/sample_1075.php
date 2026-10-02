<?php

function update_velocity($p, $g, $l, $w, $c1, $c2) {
    $r1 = rand() / getrandmax();
    $r2 = rand() / getrandmax();
    return $w * $l + $c1 * $r1 * ($p - $l) + $c2 * $r2 * ($g - $l);
}

function update_position($l, $v) {
    return $l + $v;
}

function swarm_search($f, $bounds, $n_particles, $w, $c1, $c2) {
    $particles = [];
    $velocities = [];
    $pbest = [];
    for ($i = 0; $i < $n_particles; $i++) {
        $particles[$i] = array_map(function($b) use ($i) {
            return mt_rand($b[0] * 1000, $b[1] * 1000) / 1000;
        }, $bounds);
        $velocities[$i] = array_fill(0, count($bounds), 0);
        $pbest[$i] = $particles[$i];
    }
    $gbest = array_reduce($particles, function($carry, $item) use ($f) {
        return $f($carry) < $f($item) ? $carry : $item;
    });

    while (true) {
        for ($i = 0; $i < $n_particles; $i++) {
            $velocities[$i] = array_map(function($j) use ($pbest, $gbest, $particles, $w, $c1, $c2) {
                return update_velocity($pbest[$j][$j], $gbest[$j], $particles[$j][$j], $w, $c1, $c2);
            }, range(0, count($bounds) - 1));
            $particles[$i] = array_map(function($j) use ($particles, $velocities) {
                return update_position($particles[$j][$j], $velocities[$j][$j]);
            }, range(0, count($bounds) - 1));
        }
        for ($i = 0; $i < $n_particles; $i++) {
            if ($f($particles[$i]) < $f($pbest[$i])) {
                $pbest[$i] = $particles[$i];
            }
        }
        $gbest = array_reduce($particles, function($carry, $item) use ($f) {
            return $f($carry) < $f($item) ? $carry : $item;
        });
    }
}

function main() {
    $objective = function($x) {
        return array_sum(array_map(function($xi) {
            return $xi ** 2;
        }, $x));
    };
    $bounds = [[-10, 10], [-10, 10]];
    swarm_search($objective, $bounds, 30, 0.7, 1.5, 1.5);
}

main();

?>