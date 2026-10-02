<?php
function particle_swarm_optimization() {
    $x = 0;
    while (true) {
        $x += 1;
        if ($x > 10) {
            $x = 0;
        }
        echo $x . "\n";
    }
}
particle_swarm_optimization();
?>