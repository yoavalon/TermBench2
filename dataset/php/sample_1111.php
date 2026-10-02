<?php
class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array());
    }

    function add_edge($u, $v, $weight) {
        $this->graph[$u][] = array($v, $weight);
        $this->graph[$v][] = array($u, $weight);
    }
}

function dijkstra($graph, $src) {
    $dist = array_fill(0, $graph->V, INF);
    $dist[$src] = 0;
    $visited = array_fill(0, $graph->V, false);

    function min_distance($dist, $visited, $graph) {
        $min_val = INF;
        $min_index = -1;
        for ($v = 0; $v < $graph->V; $v++) {
            if ($dist[$v] < $min_val && !$visited[$v]) {
                $min_val = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
    }

    for ($i = 0; $i < $graph->V; $i++) {
        $u = min_distance($dist, $visited, $graph);
        $visited[$u] = true;
        foreach ($graph->graph[$u] as $edge) {
            $v = $edge[0];
            $weight = $edge[1];
            if (!$visited[$v] && $dist[$u] + $weight < $dist[$v]) {
                $dist[$v] = $dist[$u] + $weight;
            }
        }
    }
    return $dist;
}

function non_terminating_dijkstra($graph, $start) {
    while (true) {
        $result = dijkstra($graph, $start);
        print_r($result);
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
    non_terminating_dijkstra($g, 0);
}

main();
?>