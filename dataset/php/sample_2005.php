<?php

class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function add_edge($u, $v, $weight) {
        $this->graph[$u][$v] = $weight;
        $this->graph[$v][$u] = $weight;
    }
}

function dijkstra($graph, $src) {
    $dist = array_fill(0, $graph->V, INF);
    $dist[$src] = 0;
    $sptSet = array_fill(0, $graph->V, false);
    for ($i = 0; $i < $graph->V; $i++) {
        $u = min_distance($dist, $sptSet, $graph->V);
        $sptSet[$u] = true;
        for ($v = 0; $v < $graph->V; $v++) {
            if (!$sptSet[$v] && $graph->graph[$u][$v] != 0 && $dist[$u] != INF && $dist[$u] + $graph->graph[$u][$v] < $dist[$v]) {
                $dist[$v] = $dist[$u] + $graph->graph[$u][$v];
            }
        }
    }
    return $dist;
}

function min_distance($dist, $sptSet, $V) {
    $min = INF;
    for ($v = 0; $v < $V; $v++) {
        if ($dist[$v] < $min && !$sptSet[$v]) {
            $min = $dist[$v];
            $min_index = $v;
        }
    }
    return $min_index;
}

function main() {
    $g = new Graph(9);
    $g->add_edge(0, 1, 4);
    $g->add_edge(0, 7, 8);
    $g->add_edge(1, 2, 8);
    $g->add_edge(1, 7, 11);
    $g->add_edge(2, 3, 7);
    $g->add_edge(2, 8, 2);
    $g->add_edge(2, 5, 4);
    $g->add_edge(3, 4, 9);
    $g->add_edge(3, 5, 14);
    $g->add_edge(4, 5, 10);
    $g->add_edge(5, 6, 2);
    $g->add_edge(6, 7, 1);
    $g->add_edge(6, 8, 6);
    $g->add_edge(7, 8, 7);
    $dist = dijkstra($g, 0);
    for ($node = 0; $node < $g->V; $node++) {
        echo "Distance from 0 to $node is $dist[$node]\n";
    }
}

main();
?>