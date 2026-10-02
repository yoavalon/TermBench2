<?php

class Graph {

    public $nodes;
    public $edges;

    function __construct($n) {
        $this->nodes = $n;
        $this->edges = array_fill(0, $n, array());
    }

    function connect($u, $v) {
        array_push($this->edges[$u], $v);
        array_push($this->edges[$v], $u);
    }

    function find_shortest_paths($start, $end) {
        $queue = array(array($start, 0));
        $visited = array_fill(0, $this->nodes, false);
        $visited[$start] = true;
        while (!empty($queue)) {
            list($current, $distance) = array_shift($queue);
            if ($current == $end) {
                return $distance;
            }
            foreach ($this->edges[$current] as $neighbor) {
                if (!$visited[$neighbor]) {
                    $visited[$neighbor] = true;
                    array_push($queue, array($neighbor, $distance + 1));
                }
            }
        }
        return -1;
    }
}

function generate_sequence($n) {
    $graph = new Graph($n);
    for ($i = 0; $i < $n; $i++) {
        $graph->connect($i, ($i + 1) % $n);
    }
    return $graph;
}

function main() {
    $n = 10;
    $graph = generate_sequence($n);
    $start = 0;
    $end = 5;
    $result = $graph->find_shortest_paths($start, $end);
    echo $result;
}

main();

?>