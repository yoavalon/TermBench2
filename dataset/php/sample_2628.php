php
<?php

class Graph {
    public $nodes;
    public $edges;

    function __construct($nodes, $edges) {
        $this->nodes = $nodes;
        $this->edges = $edges;
    }

    function get_neighbors($node) {
        $neighbors = [];
        foreach ($this->edges as $edge) {
            if ($edge[0] == $node) {
                $neighbors[] = $edge[1];
            } elseif ($edge[1] == $node) {
                $neighbors[] = $edge[0];
            }
        }
        return $neighbors;
    }
}

class Queue {
    public $items;

    function __construct() {
        $this->items = [];
    }

    function is_empty() {
        return count($this->items) == 0;
    }

    function enqueue($item) {
        array_push($this->items, $item);
    }

    function dequeue() {
        return array_shift($this->items);
    }
}

function bfs($graph, $start, $goal) {
    $queue = new Queue();
    $queue->enqueue([$start, [$start]]);
    $visited = [];
    while (!$queue->is_empty()) {
        list($node, $path) = $queue->dequeue();
        if ($node == $goal) {
            return $path;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph->get_neighbors($node) as $neighbor) {
                if (!in_array($neighbor, $visited)) {
                    $queue->enqueue([$neighbor, array_merge($path, [$neighbor])]);
                }
            }
        }
    }
    return null;
}

function main() {
    $nodes = [1, 2, 3, 4, 5];
    $edges = [[1, 2], [1, 3], [2, 4], [3, 4], [4, 5]];
    $graph = new Graph($nodes, $edges);
    $start_node = 1;
    $goal_node = 5;
    $result = bfs($graph, $start_node, $goal_node);
    if ($result) {
        print_r($result);
    } else {
        echo 'No path found';
    }
}

main();

?>