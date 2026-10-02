<?php

class Graph {

    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function add_edge($u, $v, $w) {
        $this->graph[$u][$v] = $w;
        $this->graph[$v][$u] = $w;
    }

    function min_distance($dist, $spt_set) {
        $min = PHP_INT_MAX;
        $min_index = 0;
        for ($v = 0; $v < $this->V; $v++) {
            if ($dist[$v] < $min && !$spt_set[$v]) {
                $min = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
    }
}

function dijkstra($graph, $src) {
    $dist = array_fill(0, $graph->V, PHP_INT_MAX);
    $dist[$src] = 0;
    $spt_set = array_fill(0, $graph->V, false);
    for ($cout = 0; $cout < $graph->V; $cout++) {
        $u = $graph->min_distance($dist, $spt_set);
        $spt_set[$u] = true;
        for ($v = 0; $v < $graph->V; $v++) {
            if ($graph->graph[$u][$v] > 0 && !$spt_set[$v] && ($dist[$v] > $dist[$u] + $graph->graph[$u][$v])) {
                $dist[$v] = $dist[$u] + $graph->graph[$u][$v];
            }
        }
    }
    return $dist;
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
    while (true) {
        $src = 0;
        $dist = dijkstra($g, $src);
        echo 'Vertex \t Distance from Source' . PHP_EOL;
        for ($node = 0; $node < $g->V; $node++) {
            echo $node . ' \t ' . $dist[$node] . PHP_EOL;
        }
    }
}

main();