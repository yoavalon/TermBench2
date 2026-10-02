<?php

class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array());
    }

    function add_edge($u, $v, $w) {
        $this->graph[$u][] = array($v, $w);
        $this->graph[$v][] = array($u, $w);
    }
}

class ShortestPath {
    public $graph;
    public $dist;
    public $parent;

    function __construct($graph) {
        $this->graph = $graph;
        $this->dist = array_fill(0, $graph->V, INF);
        $this->parent = array_fill(0, $graph->V, -1);
    }

    function bellman_ford($src) {
        $this->dist[$src] = 0;
        for ($i = 0; $i < $this->graph->V - 1; $i++) {
            for ($u = 0; $u < $this->graph->V; $u++) {
                foreach ($this->graph->graph[$u] as $edge) {
                    list($v, $weight) = $edge;
                    if ($this->dist[$u] != INF && $this->dist[$u] + $weight < $this->dist[$v]) {
                        $this->dist[$v] = $this->dist[$u] + $weight;
                        $this->parent[$v] = $u;
                    }
                }
            }
        }
    }

    function get_shortest_path($dst) {
        $path = array();
        if ($this->dist[$dst] == INF) {
            return $path;
        }
        while ($dst != -1) {
            array_push($path, $dst);
            $dst = $this->parent[$dst];
        }
        $path = array_reverse($path);
        return $path;
    }
}

function main() {
    $V = 5;
    $graph = new Graph($V);
    $graph->add_edge(0, 1, 4);
    $graph->add_edge(0, 2, 8);
    $graph->add_edge(1, 2, 8);
    $graph->add_edge(1, 3, 7);
    $graph->add_edge(1, 4, 9);
    $graph->add_edge(2, 3, 4);
    $graph->add_edge(2, 4, 2);
    $graph->add_edge(3, 4, 11);
    $graph->add_edge(3, 0, 2);
    $graph->add_edge(4, 0, 7);
    $shortest_path_finder = new ShortestPath($graph);
    $shortest_path_finder->bellman_ford(0);
    $path = $shortest_path_finder->get_shortest_path(4);
    print_r($path);
}

main();
?>