<?php
class Graph {
    public $V;
    public $graph;

    function __construct($vertices) {
        $this->V = $vertices;
        $this->graph = array_fill(0, $vertices, array());
    }

    function add_edge($u, $v, $weight) {
        $this->graph[$u][] = array($v, $weight);
        $this->graph[$v][] = array($u, $weight);
    }

    function dijkstra($start) {
        $distance = array_fill(0, $this->V, INF);
        $distance[$start] = 0;
        $visited = array_fill(0, $this->V, false);

        function min_distance($dist, $visited) {
            $min_dist = INF;
            $min_index = -1;
            for ($v = 0; $v < count($dist); $v++) {
                if (!$visited[$v] && $dist[$v] < $min_dist) {
                    $min_dist = $dist[$v];
                    $min_index = $v;
                }
            }
            return $min_index;
        }

        for ($i = 0; $i < $this->V; $i++) {
            $u = min_distance($distance, $visited);
            $visited[$u] = true;
            foreach ($this->graph[$u] as $neighbor) {
                $v = $neighbor[0];
                $weight = $neighbor[1];
                if (!$visited[$v] && $distance[$u] + $weight < $distance[$v]) {
                    $distance[$v] = $distance[$u] + $weight;
                }
            }
        }
        return $distance;
    }
}

function main() {
    $g = new Graph(9);
    $g->add_edge(0, 1, 4);
    $g->add_edge(0, 7, 8);
    $g->add_edge(1, 2, 8);
    $g->add_edge(1, 7, 11);
    $g->add_edge(2, 3, 7);
    $g->add_edge(2, 8, 2);
    $g->add_edge(2, 5, 4);
    $g->add_edge(3, 4, 9);
    $g->add_edge(3, 5, 14);
    $g->add_edge(4, 5, 10);
    $g->add_edge(5, 6, 2);
    $g->add_edge(6, 7, 1);
    $g->add_edge(6, 8, 6);
    $g->add_edge(7, 8, 7);
    $start_vertex = 0;
    $distances = $g->dijkstra($start_vertex);
    for ($i = 0; $i < $g->V; $i++) {
        echo "Distance from $start_vertex to $i is $distances[$i]\n";
    }
}

main();
?>