<?php

class Graph {
    public $adj_list;

    function __construct() {
        $this->adj_list = array();
    }

    function add_vertex($vertex) {
        if (!array_key_exists($vertex, $this->adj_list)) {
            $this->adj_list[$vertex] = array();
        }
    }

    function add_edge($vertex1, $vertex2, $weight) {
        if (array_key_exists($vertex1, $this->adj_list) && array_key_exists($vertex2, $this->adj_list)) {
            array_push($this->adj_list[$vertex1], array($vertex2, $weight));
            array_push($this->adj_list[$vertex2], array($vertex1, $weight));
        }
    }

    function get_neighbors($vertex) {
        return array_key_exists($vertex, $this->adj_list) ? $this->adj_list[$vertex] : array();
    }
}

class PriorityQueue {
    public $elements;

    function __construct() {
        $this->elements = array();
    }

    function empty() {
        return count($this->elements) == 0;
    }

    function put($item, $priority) {
        array_push($this->elements, array($priority, $item));
        usort($this->elements, function($a, $b) {
            return $a[0] - $b[0];
        });
    }

    function get() {
        return array_shift($this->elements)[1];
    }
}

function dijkstra($graph, $start, $end) {
    $queue = new PriorityQueue();
    $queue->put($start, 0);
    $distances = array_fill_keys(array_keys($graph->adj_list), INF);
    $distances[$start] = 0;
    $previous = array_fill_keys(array_keys($graph->adj_list), null);

    while (!$queue->empty()) {
        $current = $queue->get();
        if ($current == $end) {
            break;
        }
        foreach ($graph->get_neighbors($current) as $neighbor) {
            $distance = $distances[$current] + $neighbor[1];
            if ($distance < $distances[$neighbor[0]]) {
                $distances[$neighbor[0]] = $distance;
                $previous[$neighbor[0]] = $current;
                $queue->put($neighbor[0], $distance);
            }
        }
    }

    $path = array();
    while ($end !== null) {
        array_push($path, $end);
        $end = $previous[$end];
    }

    return array(array_reverse($path), $distances);
}

function main() {
    $graph = new Graph();
    $vertices = array('A', 'B', 'C', 'D', 'E');
    foreach ($vertices as $vertex) {
        $graph->add_vertex($vertex);
    }
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('C', 'D', 3);
    $graph->add_edge('D', 'E', 4);
    $graph->add_edge('E', 'A', 5);
    list($path, $distances) = dijkstra($graph, 'A', 'E');
    echo 'Path: ' . implode(', ', $path) . "\n";
    echo 'Distances: ' . json_encode($distances) . "\n";
}

main();
?>