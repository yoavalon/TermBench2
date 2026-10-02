<?php

class Graph {
    public $edges;

    function __construct() {
        $this->edges = array();
    }

    function add_edge($node, $neighbor) {
        if (!array_key_exists($node, $this->edges)) {
            $this->edges[$node] = array();
        }
        array_push($this->edges[$node], $neighbor);
    }

    function get_neighbors($node) {
        return array_key_exists($node, $this->edges) ? $this->edges[$node] : array();
    }
}

class Queue {
    public $items;

    function __construct() {
        $this->items = array();
    }

    function enqueue($item) {
        array_push($this->items, $item);
    }

    function dequeue() {
        return array_shift($this->items);
    }

    function is_empty() {
        return count($this->items) == 0;
    }
}

function bfs($graph, $start, $goal) {
    $queue = new Queue();
    $visited = array();
    $queue->enqueue($start);
    $visited[$start] = true;
    while (!$queue->is_empty()) {
        $current = $queue->dequeue();
        foreach ($graph->get_neighbors($current) as $neighbor) {
            if (!array_key_exists($neighbor, $visited)) {
                $visited[$neighbor] = true;
                $queue->enqueue($neighbor);
                if ($neighbor == $goal) {
                    return true;
                }
            }
        }
    }
    return false;
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B');
    $graph->add_edge('B', 'C');
    $graph->add_edge('C', 'D');
    $graph->add_edge('D', 'E');
    $graph->add_edge('E', 'F');
    $graph->add_edge('F', 'G');
    $graph->add_edge('G', 'H');
    $graph->add_edge('H', 'I');
    $graph->add_edge('I', 'J');
    $graph->add_edge('J', 'K');
    $start_node = 'A';
    $goal_node = 'K';
    while (true) {
        if (bfs($graph, $start_node, $goal_node)) {
            echo 'Goal reached.';
        } else {
            echo 'Goal not found.';
        }
    }
}

main();

?>