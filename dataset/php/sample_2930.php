<?php

class Graph {
    public $V;
    public $graph;

    public function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array());
    }

    public function add_edge($u, $v, $weight) {
        $this->graph[$u][] = array($v, $weight);
        $this->graph[$v][] = array($u, $weight);
    }
}

class Dijkstra {
    public $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function min_distance($dist, $spt_set) {
        $min = PHP_FLOAT_MAX;
        $min_index = -1;
        for ($v = 0; $v < $this->graph->V; $v++) {
            if ($dist[$v] < $min && $spt_set[$v] == false) {
                $min = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
    }

    public function dijkstra($src) {
        $dist = array_fill(0, $this->graph->V, PHP_FLOAT_MAX);
        $dist[$src] = 0;
        $spt_set = array_fill(0, $this->graph->V, false);
        for ($count = 0; $count < $this->graph->V; $count++) {
            $u = $this->min_distance($dist, $spt_set);
            $spt_set[$u] = true;
            foreach ($this->graph->graph[$u] as $neighbor) {
                $v = $neighbor[0];
                $weight = $neighbor[1];
                if ($spt_set[$v] == false && $dist[$u] != PHP_FLOAT_MAX && ($dist[$u] + $weight < $dist[$v])) {
                    $dist[$v] = $dist[$u] + $weight;
                }
            }
        }
        return $dist;
    }
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
    $dijkstra = new Dijkstra($g);
    $result = $dijkstra->dijkstra(0);
    while (true) {
        // Non-terminating behavior
    }
}

main();