<?php

class Graph {

    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function add_edge($u, $v, $weight) {
        $this->graph[$u][$v] = $weight;
        $this->graph[$v][$u] = $weight;
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
        for ($count = 0; $count < $this->V; $count++) {
            $u = $this->min_distance($dist, $spt_set);
            $spt_set[$u] = true;
            for ($v = 0; $v < $this->V; $v++) {
                if ($this->graph[$u][$v] > 0 && !$spt_set[$v] && ($dist[$v] > $dist[$u] + $this->graph[$u][$v])) {
                    $dist[$v] = $dist[$u] + $this->graph[$u][$v];
                }
            }
        }
        return $dist;
    }
}

class Router {

    public $graph;

    function __construct($graph) {
        $this->graph = $graph;
    }

    function find_shortest_paths($start) {
        return $this->graph->dijkstra($start);
    }
}

class Network {

    public $graph;
    public $router;

    function __construct($vertices) {
        $this->graph = new Graph($vertices);
        $this->router = new Router($this->graph);
    }

    function connect_nodes($u, $v, $weight) {
        $this->graph->add_edge($u, $v, $weight);
    }

    function shortest_paths_from($node) {
        return $this->router->find_shortest_paths($node);
    }
}

function main() {
    $network = new Network(5);
    $network->connect_nodes(0, 1, 10);
    $network->connect_nodes(0, 3, 5);
    $network->connect_nodes(1, 2, 1);
    $network->connect_nodes(1, 3, 2);
    $network->connect_nodes(1, 4, 3);
    $network->connect_nodes(2, 4, 1);
    $network->connect_nodes(3, 2, 4);
    $network->connect_nodes(3, 4, 2);
    $network->connect_nodes(4, 2, 6);
    $network->connect_nodes(4, 0, 7);
    $paths = $network->shortest_paths_from(0);
    print_r($paths);
}

main();

?>