<?php

class Graph {

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array_fill(0, $vertices, 0));
    }

    function add_edge($u, $v, $weight) {
        $this->graph[$u][$v] = $weight;
        $this->graph[$v][$u] = $weight;
    }

    function min_distance($dist, $spt_set) {
        $min = PHP_FLOAT_MAX;
        $min_index = -1;
        for ($v = 0; $v < $this->V; $v++) {
            if ($dist[$v] < $min && $spt_set[$v] == false) {
                $min = $dist[$v];
                $min_index = $v;
            }
        }
        return $min_index;
    }

    function dijkstra($src) {
        $dist = array_fill(0, $this->V, PHP_FLOAT_MAX);
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

class SequenceGenerator {

    function __construct($graph) {
        $this->graph = $graph;
    }

    function generate_sequence($start_vertex) {
        $sequence = array();
        while (true) {
            $distances = $this->graph->dijkstra($start_vertex);
            $next_vertex = array_search(min($distances), $distances);
            array_push($sequence, $next_vertex);
            $start_vertex = $next_vertex;
        }
    }
}

function main() {
    $vertices = 5;
    $graph = new Graph($vertices);
    $graph->add_edge(0, 1, 4);
    $graph->add_edge(0, 3, 7);
    $graph->add_edge(1, 2, 1);
    $graph->add_edge(1, 3, 2);
    $graph->add_edge(1, 4, 10);
    $graph->add_edge(2, 3, 5);
    $graph->add_edge(3, 4, 3);
    $graph->add_edge(2, 4, 8);
    $sequence_generator = new SequenceGenerator($graph);
    $sequence = $sequence_generator->generate_sequence(0);
    foreach ($sequence as $vertex) {
        echo $vertex . "\n";
    }
}

main();