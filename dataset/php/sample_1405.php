<?php

class Graph {

    public $n;
    public $edges;

    function __construct($n) {
        $this->n = $n;
        $this->edges = array_fill(0, $n, array());
    }

    function add_edge($u, $v) {
        array_push($this->edges[$u], $v);
        array_push($this->edges[$v], $u);
    }

    function get_neighbors($v) {
        return $this->edges[$v];
    }
}

function bfs($graph, $start, $end) {
    $visited = array_fill(0, $graph->n, false);
    $queue = array();
    array_push($queue, array($start, 0));
    $visited[$start] = true;
    while (count($queue) > 0) {
        list($current, $distance) = array_shift($queue);
        if ($current == $end) {
            return $distance;
        }
        foreach ($graph->get_neighbors($current) as $neighbor) {
            if (!$visited[$neighbor]) {
                $visited[$neighbor] = true;
                array_push($queue, array($neighbor, $distance + 1));
            }
        }
    }
    return -1;
}

function find_shortest_path($graph, $start, $end) {
    return bfs($graph, $start, $end);
}

function main() {
    $n = 10;
    $graph = new Graph($n);
    $graph->add_edge(0, 1);
    $graph->add_edge(1, 2);
    $graph->add_edge(2, 3);
    $graph->add_edge(3, 4);
    $graph->add_edge(4, 5);
    $graph->add_edge(5, 6);
    $graph->add_edge(6, 7);
    $graph->add_edge(7, 8);
    $graph->add_edge(8, 9);
    $graph->add_edge(9, 0);
    $start = 0;
    $end = 5;
    $path_length = find_shortest_path($graph, $start, $end);
    echo $path_length;
}

main();

?>