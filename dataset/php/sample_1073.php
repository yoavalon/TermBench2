<?php

function update_position($position, $velocity, $p_best, $g_best) {
    $r1 = rand() / getrandmax();
    $r2 = rand() / getrandmax();
    $c1 = 1.5;
    $c2 = 1.5;
    $new_velocity = $velocity + $c1 * $r1 * ($p_best - $position) + $c2 * $r2 * ($g_best - $position);
    $new_position = $position + $new_velocity;
    return array($new_position, $new_velocity);
}

function optimize() {
    $particles = array(array('position' => rand(-10, 10), 'velocity' => rand(-1, 1), 'p_best' => null));
    $g_best = $particles[0]['position'];
    while (true) {
        foreach ($particles as &$particle) {
            if ($particle['p_best'] === null) {
                $particle['p_best'] = $particle['position'];
            } elseif ($particle['position'] < $particle['p_best']) {
                $particle['p_best'] = $particle['position'];
            }
            if ($particle['position'] < $g_best) {
                $g_best = $particle['position'];
            }
        }
        foreach ($particles as &$particle) {
            list($particle['position'], $particle['velocity']) = update_position($particle['position'], $particle['velocity'], $particle['p_best'], $g_best);
        }
    }
}

optimize();
?>