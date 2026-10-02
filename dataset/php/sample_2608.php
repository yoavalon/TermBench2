<?php

class Graph {
    public $nodes;
    public $adj_list;

    function __construct($nodes) {
        $this->nodes = $nodes;
        $this->adj_list = array_fill_keys($nodes, array());
    }

    function add_edge($node1, $node2) {
        $this->adj_list[$node1][] = $node2;
        $this->adj_list[$node2][] = $node1;
    }
}

class ShortestPathFinder {
    public $graph;

    function __construct($graph) {
        $this->graph = $graph;
    }

    function bfs($start, $end) {
        $queue = array(array($start, 0));
        $visited = array();
        while (!empty($queue)) {
            list($node, $dist) = array_shift($queue);
            if ($node == $end) {
                return $dist;
            }
            if (!in_array($node, $visited)) {
                $visited[] = $node;
                foreach ($this->graph->adj_list[$node] as $neighbor) {
                    $queue[] = array($neighbor, $dist + 1);
                }
            }
        }
        return -1;
    }
}

function main() {
    $nodes = array(0, 1, 2, 3, 4, 5, 6);
    $graph = new Graph($nodes);
    $graph->add_edge(0, 1);
    $graph->add_edge(1, 2);
    $graph->add_edge(2, 3);
    $graph->add_edge(3, 4);
    $graph->add_edge(4, 5);
    $graph->add_edge(5, 6);
    $graph->add_edge(0, 3);
    $graph->add_edge(3, 6);
    $spf = new ShortestPathFinder($graph);
    $result = $spf->bfs(0, 6);
    echo $result;
}

main();

?>