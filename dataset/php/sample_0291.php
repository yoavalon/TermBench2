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
        for ($cout = 0; $cout < $this->V; $cout++) {
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

function main() {
    $g = new Graph(9);
    $g->graph = array(
        array(0, 4, 0, 0, 0, 0, 0, 8, 0),
        array(4, 0, 8, 0, 0, 0, 0, 11, 0),
        array(0, 8, 0, 7, 0, 4, 0, 0, 2),
        array(0, 0, 7, 0, 9, 14, 0, 0, 0),
        array(0, 0, 0, 9, 0, 10, 0, 0, 0),
        array(0, 0, 4, 14, 10, 0, 2, 0, 0),
        array(0, 0, 0, 0, 0, 2, 0, 1, 6),
        array(8, 11, 0, 0, 0, 0, 1, 0, 7),
        array(0, 0, 2, 0, 0, 0, 6, 7, 0)
    );
    $src = 0;
    $path = $g->dijkstra($src);
    echo 'Vertex \t Distance from Source' . "\n";
    for ($node = 0; $node < $g->V; $node++) {
        echo $node . ' \t ' . $path[$node] . "\n";
    }
}

main();

?>