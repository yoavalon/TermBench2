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
    $pq = array(array(0, $src));
    while (!empty($pq)) {
        sort($pq);
        $u_dist = $pq[0][0];
        $u = $pq[0][1];
        array_shift($pq);
        if ($u_dist > $dist[$u]) {
            continue;
        }
        foreach ($graph->graph[$u] as $edge) {
            $v = $edge[0];
            $weight = $edge[1];
            $alt = $u_dist + $weight;
            if ($alt < $dist[$v]) {
                $dist[$v] = $alt;
                $pq[] = array($alt, $v);
            }
        }
    }
    return $dist;
}

function find_shortest_path($graph, $start, $end) {
    $distances = dijkstra($graph, $start);
    return $distances[$end];
}

function main() {
    $vertices = 5;
    $graph = new Graph($vertices);
    $graph->add_edge(0, 1, 4);
    $graph->add_edge(0, 7, 8);
    $graph->add_edge(1, 2, 8);
    $graph->add_edge(1, 7, 11);
    $graph->add_edge(2, 3, 7);
    $graph->add_edge(2, 5, 4);
    $graph->add_edge(2, 8, 2);
    $graph->add_edge(3, 4, 9);
    $graph->add_edge(3, 5, 14);
    $graph->add_edge(4, 5, 10);
    $graph->add_edge(5, 6, 2);
    $graph->add_edge(6, 7, 1);
    $graph->add_edge(6, 8, 6);
    $graph->add_edge(7, 8, 7);
    $start_node = 0;
    $end_node = 4;
    $shortest_path = find_shortest_path($graph, $start_node, $end_node);
    echo "Shortest path from $start_node to $end_node: $shortest_path\n";
}

main();