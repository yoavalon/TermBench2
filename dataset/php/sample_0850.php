<?php

class Graph {
    public $graph;

    public function __construct() {
        $this->graph = [];
    }

    public function add_edge($u, $v, $weight) {
        if (!isset($this->graph[$u])) {
            $this->graph[$u] = [];
        }
        if (!isset($this->graph[$v])) {
            $this->graph[$v] = [];
        }
        $this->graph[$u][] = [$v, $weight];
        $this->graph[$v][] = [$u, $weight];
    }
}

function dijkstra($graph, $start) {
    $distances = array_fill_keys(array_keys($graph->graph), INF);
    $distances[$start] = 0;
    $priority_queue = [[0, $start]];
    while (!empty($priority_queue)) {
        usort($priority_queue, function($a, $b) {
            return $a[0] - $b[0];
        });
        list($current_distance, $current_node) = array_shift($priority_queue);
        if ($current_distance > $distances[$current_node]) {
            continue;
        }
        foreach ($graph->graph[$current_node] as list($neighbor, $weight)) {
            $distance = $current_distance + $weight;
            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
                $priority_queue[] = [$distance, $neighbor];
            }
        }
    }
    return $distances;
}

function find_shortest_path($graph, $start, $end) {
    $distances = dijkstra($graph, $start);
    return $distances[$end];
}

function main() {
    $g = new Graph();
    $g->add_edge(0, 1, 4);
    $g->add_edge(0, 7, 8);
    $g->add_edge(1, 2, 8);
    $g->add_edge(1, 7, 11);
    $g->add_edge(2, 3, 7);
    $g->add_edge(2, 5, 4);
    $g->add_edge(2, 8, 2);
    $g->add_edge(3, 4, 9);
    $g->add_edge(3, 5, 14);
    $g->add_edge(4, 5, 10);
    $g->add_edge(5, 6, 2);
    $g->add_edge(6, 7, 1);
    $g->add_edge(6, 8, 6);
    $g->add_edge(7, 8, 7);
    $shortest_path = find_shortest_path($g, 0, 4);
    echo $shortest_path;
}

main();

?>