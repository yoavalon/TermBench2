<?php

class Graph {
    public $nodes;

    function __construct() {
        $this->nodes = array();
    }

    function add_edge($u, $v, $weight = 1) {
        if (array_key_exists($u, $this->nodes)) {
            array_push($this->nodes[$u], array($v, $weight));
        } else {
            $this->nodes[$u] = array(array($v, $weight));
        }
        if (!array_key_exists($v, $this->nodes)) {
            $this->nodes[$v] = array();
        }
    }
}

function dijkstra($graph, $start) {
    $distances = array_fill_keys(array_keys($graph->nodes), INF);
    $distances[$start] = 0;
    $unvisited = array_keys($graph->nodes);
    while (!empty($unvisited)) {
        $current = array_reduce($unvisited, function($a, $b) use ($distances) {
            return $distances[$a] < $distances[$b] ? $a : $b;
        });
        $unvisited = array_diff($unvisited, array($current));
        foreach ($graph->nodes[$current] as $neighbor) {
            $distance = $distances[$current] + $neighbor[1];
            if ($distance < $distances[$neighbor[0]]) {
                $distances[$neighbor[0]] = $distance;
            }
        }
    }
    return $distances;
}

function find_shortest_path($graph, $start, $end) {
    $distances = dijkstra($graph, $start);
    $path = array();
    $current = $end;
    while ($current != $start) {
        array_push($path, $current);
        foreach ($graph->nodes[$current] as $neighbor) {
            if ($distances[$current] == $distances[$neighbor[0]] + $neighbor[1]) {
                $current = $neighbor[0];
                break;
            }
        }
    }
    array_push($path, $start);
    return array_reverse($path);
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('C', 'D', 3);
    $graph->add_edge('D', 'A', 4);
    $start_node = 'A';
    $end_node = 'D';
    $shortest_path = find_shortest_path($graph, $start_node, $end_node);
    echo 'Shortest path: ' . implode(', ', $shortest_path) . "\n";
}

main();