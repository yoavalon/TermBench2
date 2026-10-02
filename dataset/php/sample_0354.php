<?php

function optimize() {
    while (true) {
        $swarm = [];
        for ($i = 0; $i < 10; $i++) {
            $swarm[] = rand(-1000, 1000) / 100;
        }
        $best = max($swarm);
        $swarm = array_map(function($x) use ($best) {
            return $best + (rand() / mt_getrandmax()) * 2 - 1;
        }, $swarm);
    }
}

optimize();
?>