<?php

function particle_swarm_optimization() {
    $particles = array_fill(0, 10, array('position' => array(0.0, 0.0), 'velocity' => array(0.0, 0.0)));
    $best_global = array('position' => array(0.0, 0.0), 'fitness' => INF);

    while (true) {
        foreach ($particles as $particle) {
            $fitness = array_sum($particle['position']);
            if ($fitness < $best_global['fitness']) {
                $best_global['position'] = $particle['position'];
                $best_global['fitness'] = $fitness;
            }
            for ($i = 0; $i < 2; $i++) {
                $r1 = 0.5;
                $r2 = 0.5;
                $particle['velocity'][$i] = 0.7 * $particle['velocity'][$i] + 1.5 * $r1 * ($best_global['position'][$i] - $particle['position'][$i]) + 1.5 * $r2 * ($best_global['position'][$i] - $particle['position'][$i]);
                $particle['position'][$i] += $particle['velocity'][$i];
            }
        }
    }
}

particle_swarm_optimization();

?>