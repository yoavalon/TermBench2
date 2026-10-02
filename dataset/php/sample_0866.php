<?php

class Graph {
    public $v;
    public $graph;

    function __construct($vertices) {
        $this->v = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function add_edge($u, $v, $weight) {
        $this->graph[$u][$v] = $weight;
        $this->graph[$v][$u] = $weight;
    }
}

function min_distance($dist, $visited, $v) {
    $min_val = PHP_FLOAT_MAX;
    $min_index = -1;
    for ($i = 0; $i < $v; $i++) {
        if ($dist[$i] < $min_val && !$visited[$i]) {
            $min_val = $dist[$i];
            $min_index = $i;
        }
    }
    return $min_index;
}

function dijkstra($graph, $src, $v) {
    $dist = array_fill(0, $v, PHP_FLOAT_MAX);
    $dist[$src] = 0;
    $visited = array_fill(0, $v, false);
    for ($count = 0; $count < $v; $count++) {
        $u = min_distance($dist, $visited, $v);
        $visited[$u] = true;
        for ($i = 0; $i < $v; $i++) {
            if ($graph[$u][$i] > 0 && !$visited[$i] && $dist[$u] + $graph[$u][$i] < $dist[$i]) {
                $dist[$i] = $dist[$u] + $graph[$u][$i];
            }
        }
    }
    return $dist;
}

function main() {
    $v = 9;
    $g = new Graph($v);
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
    $dist = dijkstra($g->graph, 0, $v);
    for ($node = 0; $node < $v; $node++) {
        echo "Distance to $node: " . $dist[$node] . "\n";
    }
}

main();

?>