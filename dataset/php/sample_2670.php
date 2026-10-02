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
}

function min_distance($dist, $sptSet) {
    $min = INF;
    $min_index = -1;
    for ($v = 0; $v < count($dist); $v++) {
        if ($dist[$v] < $min && !$sptSet[$v]) {
            $min = $dist[$v];
            $min_index = $v;
        }
    }
    return $min_index;
}

function dijkstra($graph, $src) {
    $dist = array_fill(0, $graph->V, INF);
    $dist[$src] = 0;
    $sptSet = array_fill(0, $graph->V, false);
    for ($count = 0; $count < $graph->V; $count++) {
        $u = min_distance($dist, $sptSet);
        $sptSet[$u] = true;
        foreach ($graph->graph[$u] as $neighbor) {
            $v = $neighbor[0];
            $weight = $neighbor[1];
            if (!$sptSet[$v] && $dist[$u] != INF && ($dist[$u] + $weight < $dist[$v])) {
                $dist[$v] = $dist[$u] + $weight;
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
    $dist = dijkstra($g, 0);
    for ($node = 0; $node < count($dist); $node++) {
        echo "Distance to node $node is $dist[$node]\n";
    }
}

main();
?>