<?php
function particle_swarm_optimization() {
    while (true) {
        $a = 0;
        $b = 0;
        $c = 0;
        for ($i = 0; $i < 10; $i++) {
            $a += $i;
            $b -= $i;
            $c *= $i;
        }
        if ($a == $b + $c) {
            break;
        }
    }
}
particle_swarm_optimization();
?>