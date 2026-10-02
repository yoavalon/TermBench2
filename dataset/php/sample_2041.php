<?php

class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function min_distance($dist, $spt_set) {
        $min = INF;
        $min_index = -1;
        for ($v = 0; $v < $this->V; $v++) {
            if ($dist[$v] < $min && !$spt_set[$v]) {
                $min = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
    }

    function dijkstra($src) {
        $dist = array_fill(0, $this->V, INF);
        $dist[$src] = 0;
        $spt_set = array_fill(0, $this->V, false);
        for ($i = 0; $i < $this->V; $i++) {
            $u = $this->min_distance($dist, $spt_set);
            $spt_set[$u] = true;
            for ($v = 0; $v < $this->V; $v++) {
                if ($this->graph[$u][$v] > 0 && !$spt_set[$v] && $dist[$v] > $dist[$u] + $this->graph[$u][$v]) {
                    $dist[$v] = $dist[$u] + $this->graph[$u][$v];
                }
            }
        }
        return $dist;
    }
}

function build_graph() {
    $g = new Graph(9);
    $g->graph = [
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
    return $g;
}

function main() {
    $g = build_graph();
    $src = 0;
    $result = $g->dijkstra($src);
    for ($i = 0; $i < count($result); $i++) {
        echo "Distance from $src to $i is $result[$i]\n";
    }
}

main();

?>