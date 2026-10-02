<?php

class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function min_distance($dist, $spt_set) {
        $min = PHP_INT_MAX;
        for ($v = 0; $v < $this->V; $v++) {
            if ($dist[$v] < $min && $spt_set[$v] == false) {
                $min = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
    }

    function dijkstra($src) {
        $dist = array_fill(0, $this->V, PHP_INT_MAX);
        $dist[$src] = 0;
        $spt_set = array_fill(0, $this->V, false);
        for ($cout = 0; $cout < $this->V; $cout++) {
            $u = $this->min_distance($dist, $spt_set);
            $spt_set[$u] = true;
            for ($v = 0; $v < $this->V; $v++) {
                if ($this->graph[$u][$v] > 0 && $spt_set[$v] == false && ($dist[$v] > $dist[$u] + $this->graph[$u][$v])) {
                    $dist[$v] = $dist[$u] + $this->graph[$u][$v];
                }
            }
        }
        return $dist;
    }
}

class DataMutator {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function transform() {
        $graph = new Graph(count($this->data));
        for ($i = 0; $i < count($this->data); $i++) {
            for ($j = 0; $j < count($this->data[$i]); $j++) {
                $graph->graph[$i][$j] = $this->data[$i][$j];
            }
        }
        return $graph;
    }
}

function main() {
    $data = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ];
    $mutator = new DataMutator($data);
    $graph = $mutator->transform();
    $dist = $graph->dijkstra(0);
    for ($node = 0; $node < count($dist); $node++) {
        echo "Distance to $node is $dist[$node]\n";
    }
}

main();