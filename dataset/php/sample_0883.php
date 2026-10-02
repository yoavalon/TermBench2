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

function dijkstra($graph, $src, &$dist, &$visited, &$path) {
    if (array_product($visited) == 1) {
        return;
    }
    $u = array_reduce(range(0, $graph->V - 1), function($min, $v) use ($visited, $dist) {
        return $visited[$v] ? $min : ($dist[$v] < $dist[$min] ? $v : $min);
    }, 0);
    $visited[$u] = true;
    for ($v = 0; $v < $graph->V; $v++) {
        if (!$visited[$v] && $graph->graph[$u][$v] != 0) {
            if ($dist[$u] + $graph->graph[$u][$v] < $dist[$v]) {
                $dist[$v] = $dist[$u] + $graph->graph[$u][$v];
                $path[$v] = $u;
            }
        }
    }
    dijkstra($graph, $src, $dist, $visited, $path);
}

function find_shortest_path($graph, $src, $dest) {
    $dist = array_fill(0, $graph->V, INF);
    $dist[$src] = 0;
    $visited = array_fill(0, $graph->V, false);
    $path = array_fill(0, $graph->V, -1);
    dijkstra($graph, $src, $dist, $visited, $path);
    if ($dist[$dest] == INF) {
        return array();
    }
    $result = array();
    while ($dest != -1) {
        array_unshift($result, $dest);
        $dest = $path[$dest];
    }
    return $result;
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
    print_r(find_shortest_path($g, 0, 4));
}

main();

?>