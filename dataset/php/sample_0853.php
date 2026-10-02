<?php

class Graph {
    private $adj_list;

    public function __construct() {
        $this->adj_list = [];
    }

    public function add_vertex($vertex) {
        if (!array_key_exists($vertex, $this->adj_list)) {
            $this->adj_list[$vertex] = [];
        }
    }

    public function add_edge($vertex1, $vertex2, $weight) {
        if (array_key_exists($vertex1, $this->adj_list) && array_key_exists($vertex2, $this->adj_list)) {
            $this->adj_list[$vertex1][] = [$vertex2, $weight];
            $this->adj_list[$vertex2][] = [$vertex1, $weight];
        }
    }

    public function get_neighbors($vertex) {
        return isset($this->adj_list[$vertex]) ? $this->adj_list[$vertex] : [];
    }
}

class Dijkstra {
    private $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function find_shortest_path($start, $end) {
        $distances = array_fill_keys(array_keys($this->graph->adj_list), INF);
        $distances[$start] = 0;
        $priority_queue = [[0, $start]];

        while (!empty($priority_queue)) {
            usort($priority_queue, function($a, $b) { return $a[0] <=> $b[0]; });
            list($current_distance, $current_vertex) = array_shift($priority_queue);

            if ($current_distance > $distances[$current_vertex]) {
                continue;
            }

            foreach ($this->graph->get_neighbors($current_vertex) as $neighbor) {
                list($neighbor_vertex, $weight) = $neighbor;
                $distance = $current_distance + $weight;

                if ($distance < $distances[$neighbor_vertex]) {
                    $distances[$neighbor_vertex] = $distance;
                    $priority_queue[] = [$distance, $neighbor_vertex];
                }
            }
        }

        return $distances[$end];
    }
}

function main() {
    $g = new Graph();
    $g->add_vertex('A');
    $g->add_vertex('B');
    $g->add_vertex('C');
    $g->add_vertex('D');
    $g->add_vertex('E');
    $g->add_edge('A', 'B', 1);
    $g->add_edge('B', 'C', 2);
    $g->add_edge('C', 'D', 3);
    $g->add_edge('D', 'E', 4);
    $g->add_edge('A', 'E', 10);
    $dijkstra = new Dijkstra($g);
    $result = $dijkstra->find_shortest_path('A', 'E');
    echo $result;
}

main();

?>