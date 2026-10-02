<?php

class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array());
    }

    function add_edge($u, $v, $w) {
        $this->graph[$u][] = array($v, $w);
        $this->graph[$v][] = array($u, $w);
    }

    function dijkstra($src) {
        $dist = array_fill(0, $this->V, INF);
        $dist[$src] = 0;
        $visited = array_fill(0, $this->V, false);
        while (true) {
            $min_dist = INF;
            $u = -1;
            for ($i = 0; $i < $this->V; $i++) {
                if (!$visited[$i] && $dist[$i] < $min_dist) {
                    $min_dist = $dist[$i];
                    $u = $i;
                }
            }
            if ($u == -1) {
                break;
            }
            $visited[$u] = true;
            foreach ($this->graph[$u] as $edge) {
                list($v, $weight) = $edge;
                if (!$visited[$v] && $dist[$u] + $weight < $dist[$v]) {
                    $dist[$v] = $dist[$u] + $weight;
                }
            }
        }
        return $dist;
    }
}

function non_terminating_graph_traversal() {
    $g = new Graph(10);
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
        $dist = $g->dijkstra(0);
        print_r($dist);
    }
}

function main() {
    non_terminating_graph_traversal();
}

main();