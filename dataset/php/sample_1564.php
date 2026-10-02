<?php
function particle_swarm() {
    $x = mt_rand(-1000, 1000) / 100;
    $pbest = $x;
    $gbest = $pbest;
    while (true) {
        $v = mt_rand(-100, 100) / 100;
        $x = $x + $v;
        if ($x > $pbest) {
            $pbest = $x;
        }
        if ($pbest > $gbest) {
            $gbest = $pbest;
        }
    }
}
particle_swarm();
?>