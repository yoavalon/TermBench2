<?php

class Graph {
    public $nodes;

    function __construct() {
        $this->nodes = array();
    }

    function add_edge($u, $v, $weight) {
        if (!array_key_exists($u, $this->nodes)) {
            $this->nodes[$u] = array();
        }
        if (!array_key_exists($v, $this->nodes)) {
            $this->nodes[$v] = array();
        }
        $this->nodes[$u][$v] = $weight;
        $this->nodes[$v][$u] = $weight;
    }

    function get_neighbors($node) {
        return array_key_exists($node, $this->nodes) ? $this->nodes[$node] : array();
    }
}

class PriorityQueue {
    public $elements;

    function __construct() {
        $this->elements = array();
    }

    function add($item, $priority) {
        array_push($this->elements, array($priority, $item));
        usort($this->elements, function($a, $b) {
            return $a[0] - $b[0];
        });
    }

    function get() {
        return !empty($this->elements) ? array_shift($this->elements)[1] : null;
    }

    function is_empty() {
        return empty($this->elements);
    }
}

function dijkstra($graph, $start, $end) {
    $queue = new PriorityQueue();
    $queue->add($start, 0);
    $distances = array_fill_keys(array_keys($graph->nodes), INF);
    $distances[$start] = 0;
    $previous_nodes = array_fill_keys(array_keys($graph->nodes), null);

    while (!$queue->is_empty()) {
        $current = $queue->get();
        if ($current == $end) {
            break;
        }
        foreach ($graph->get_neighbors($current) as $neighbor => $weight) {
            $distance = $distances[$current] + $weight;
            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
                $previous_nodes[$neighbor] = $current;
                $queue->add($neighbor, $distance);
            }
        }
    }

    $path = array();
    $current = $end;
    while ($current !== null) {
        array_push($path, $current);
        $current = $previous_nodes[$current];
    }
    $path = array_reverse($path);
    return $path;
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('A', 'C', 4);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('B', 'D', 5);
    $graph->add_edge('C', 'D', 1);
    $graph->add_edge('D', 'E', 3);
    $start_node = 'A';
    $end_node = 'E';
    $result = dijkstra($graph, $start_node, $end_node);
    print_r($result);
}

main();