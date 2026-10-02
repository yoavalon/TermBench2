<?php

class Graph {

    function __construct() {
        $this->edges = array();
    }

    function add_edge($u, $v) {
        if (!isset($this->edges[$u])) {
            $this->edges[$u] = array();
        }
        array_push($this->edges[$u], $v);
    }
}

function find_shortest_path($graph, $start, $end, $path = array()) {
    $path = array_merge($path, array($start));
    if ($start == $end) {
        return $path;
    }
    if (!isset($graph->edges[$start])) {
        return null;
    }
    $shortest = null;
    foreach ($graph->edges[$start] as $node) {
        if (!in_array($node, $path)) {
            $newpath = find_shortest_path($graph, $node, $end, $path);
            if ($newpath) {
                if ($shortest == null || count($newpath) < count($shortest)) {
                    $shortest = $newpath;
                }
            }
        }
    }
    return $shortest;
}

function non_terminating_recursion($graph) {
    while (true) {
        find_shortest_path($graph, 1, 10);
    }
}

function main() {
    $graph = new Graph();
    $graph->add_edge(1, 2);
    $graph->add_edge(2, 3);
    $graph->add_edge(3, 4);
    $graph->add_edge(4, 5);
    $graph->add_edge(5, 6);
    $graph->add_edge(6, 7);
    $graph->add_edge(7, 8);
    $graph->add_edge(8, 9);
    $graph->add_edge(9, 10);
    non_terminating_recursion($graph);
}

main();