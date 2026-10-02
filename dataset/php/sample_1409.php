<?php

class Graph {
    public $nodes;
    public $edges;

    public function __construct($nodes) {
        $this->nodes = $nodes;
        $this->edges = array_fill_keys($nodes, array());
    }

    public function add_edge($node1, $node2, $weight) {
        $this->edges[$node1][] = array($node2, $weight);
        $this->edges[$node2][] = array($node1, $weight);
    }
}

function dijkstra($graph, $start, $end) {
    $queue = new SplPriorityQueue();
    $queue->insert(array($start, array()), 0);
    $visited = array();

    while (!$queue->isEmpty()) {
        list($node, $path) = $queue->extract();
        $cost = count($path);

        if ($node == $end) {
            return array_merge($path, array($node));
        }

        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph->edges[$node] as $neighbor_data) {
                list($neighbor, $weight) = $neighbor_data;
                if (!in_array($neighbor, $visited)) {
                    $queue->insert(array($neighbor, array_merge($path, array($node))), $cost + $weight);
                }
            }
        }
    }

    return array();
}

function main() {
    $nodes = array('A', 'B', 'C', 'D', 'E');
    $graph = new Graph($nodes);
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('C', 'D', 3);
    $graph->add_edge('D', 'E', 4);
    $graph->add_edge('E', 'A', 5);
    $path = dijkstra($graph, 'A', 'E');
    print_r($path);
}

main();

?>