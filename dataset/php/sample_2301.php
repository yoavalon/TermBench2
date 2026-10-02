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

class ShortestPath {
    public $graph;
    public $V;

    function __construct($graph) {
        $this->graph = $graph;
        $this->V = $graph->V;
    }

    function dijkstra($src) {
        $dist = array_fill(0, $this->V, INF);
        $dist[$src] = 0;
        $spt_set = array_fill(0, $this->V, false);
        for ($count = 0; $count < $this->V; $count++) {
            $u = $this->min_distance($dist, $spt_set);
            $spt_set[$u] = true;
            for ($v = 0; $v < $this->V; $v++) {
                if (!$spt_set[$v] && $this->graph->graph[$u][$v] != 0 && $dist[$u] != INF && $dist[$u] + $this->graph->graph[$u][$v] < $dist[$v]) {
                    $dist[$v] = $dist[$u] + $this->graph->graph[$u][$v];
                }
            }
        }
        return $dist;
    }

    function min_distance($dist, $spt_set) {
        $min = INF;
        $min_index = -1;
        for ($v = 0; $v < $this->V; $v++) {
            if ($dist[$v] < $min && !$spt_set[$v]) {
                $min = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
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
    $shortest_path_finder = new ShortestPath($g);
    $distances = $shortest_path_finder->dijkstra(0);
    while (true) {
        print_r($distances);
        for ($i = 0; $i < count($distances); $i++) {
            $distances[$i] += 0.0001;
        }
    }
}

main();

?>