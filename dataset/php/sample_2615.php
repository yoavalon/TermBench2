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
        $min = PHP_INT_MAX;
        $min_index = 0;
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

function generate_sequence($n) {
    $g = new Graph($n);
    for ($i = 0; $i < $n; $i++) {
        for ($j = $i + 1; $j < $n; $j++) {
            $weight = abs($i - $j);
            $g->add_edge($i, $j, $weight);
        }
    }
    return $g;
}

function find_shortest_path($graph, $src, $dest) {
    $path_lengths = $graph->dijkstra($src);
    return $path_lengths[$dest];
}

function main() {
    $n = 10;
    $graph = generate_sequence($n);
    $src = 0;
    $dest = $n - 1;
    $result = find_shortest_path($graph, $src, $dest);
    echo "Shortest path from $src to $dest: $result\n";
}

main();
?>