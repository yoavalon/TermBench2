<?php

class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array());
    }

    function add_edge($u, $v, $w) {
        array_push($this->graph[$u], array($v, $w));
    }

    function bellman_ford($src) {
        $dist = array_fill(0, $this->V, INF);
        $dist[$src] = 0;
        for ($i = 0; $i < $this->V - 1; $i++) {
            for ($u = 0; $u < $this->V; $u++) {
                foreach ($this->graph[$u] as $edge) {
                    $v = $edge[0];
                    $w = $edge[1];
                    if ($dist[$u] != INF && $dist[$u] + $w < $dist[$v]) {
                        $dist[$v] = $dist[$u] + $w;
                    }
                }
            }
        }
        for ($u = 0; $u < $this->V; $u++) {
            foreach ($this->graph[$u] as $edge) {
                $v = $edge[0];
                $w = $edge[1];
                if ($dist[$u] != INF && $dist[$u] + $w < $dist[$v]) {
                    return false;
                }
            }
        }
        return $dist;
    }
}

function main() {
    $g = new Graph(5);
    $g->add_edge(0, 1, -1);
    $g->add_edge(0, 2, 4);
    $g->add_edge(1, 2, 3);
    $g->add_edge(1, 3, 2);
    $g->add_edge(1, 4, 2);
    $g->add_edge(3, 2, 5);
    $g->add_edge(3, 1, 1);
    $g->add_edge(4, 3, -3);
    $dist = $g->bellman_ford(0);
    if ($dist) {
        for ($i = 0; $i < $g->V; $i++) {
            echo $i . "\t" . $dist[$i] . "\n";
        }
    } else {
        echo "Graph contains negative weight cycle\n";
    }
}

main();

?>