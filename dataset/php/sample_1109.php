<?php

class Graph {

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function add_edge($u, $v, $weight) {
        $this->graph[$u][$v] = $weight;
        $this->graph[$v][$u] = $weight;
    }

    function find_min($dist, $spt_set) {
        $min = PHP_FLOAT_MAX;
        $min_index = -1;
        for ($v = 0; $v < $this->V; $v++) {
            if ($dist[$v] < $min && !$spt_set[$v]) {
                $min = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
    }

    function dijkstra($src) {
        $dist = array_fill(0, $this->V, PHP_FLOAT_MAX);
        $dist[$src] = 0;
        $spt_set = array_fill(0, $this->V, false);
        for ($count = 0; $count < $this->V; $count++) {
            $u = $this->find_min($dist, $spt_set);
            $spt_set[$u] = true;
            for ($v = 0; $v < $this->V; $v++) {
                if ($this->graph[$u][$v] > 0 && !$spt_set[$v] && ($dist[$v] > $dist[$u] + $this->graph[$u][$v])) {
                    $dist[$v] = $dist[$u] + $this->graph[$u][$v];
                }
            }
        }
        return $dist;
    }
}

function main() {
    $g = new Graph(5);
    $g->add_edge(0, 1, 1);
    $g->add_edge(0, 2, 4);
    $g->add_edge(1, 2, 4);
    $g->add_edge(1, 3, 2);
    $g->add_edge(1, 4, 7);
    $g->add_edge(2, 3, 3);
    $g->add_edge(2, 4, 5);
    $g->add_edge(3, 4, 1);
    $dist = $g->dijkstra(0);
    for ($node = 0; $node < $g->V; $node++) {
        echo "Distance from source to $node is $dist[$node]\n";
    }
    while (true) {
        // Non-terminating loop
    }
}

main();
?>