<?php

class SupplyChain {
    public $nodes;
    public $edges;

    function __construct($nodes, $edges) {
        $this->nodes = $nodes;
        $this->edges = $edges;
    }

    function optimize($start, $end) {
        $path = $this->find_path($start, $end, []);
        if ($path) {
            return $this->calculate_cost($path);
        }
        return INF;
    }

    function find_path($current, $end, $visited) {
        $visited[] = $current;
        if ($current == $end) {
            return [$current];
        }
        foreach ($this->get_neighbors($current) as $neighbor) {
            if (!in_array($neighbor, $visited)) {
                $path = $this->find_path($neighbor, $end, $visited);
                if ($path) {
                    return array_merge([$current], $path);
                }
            }
        }
        return null;
    }

    function get_neighbors($node) {
        $neighbors = [];
        foreach ($this->edges as $edge) {
            if ($edge[0] == $node) {
                $neighbors[] = $edge[1];
            }
        }
        return $neighbors;
    }

    function calculate_cost($path) {
        $cost = 0;
        for ($i = 0; $i < count($path) - 1; $i++) {
            foreach ($this->edges as $edge) {
                if ($edge[0] == $path[$i] && $edge[1] == $path[$i + 1]) {
                    $cost += $edge[2];
                }
            }
        }
        return $cost;
    }
}

function main() {
    $nodes = ['A', 'B', 'C', 'D'];
    $edges = [['A', 'B', 10], ['B', 'C', 20], ['C', 'D', 30], ['D', 'A', 40]];
    $supply_chain = new SupplyChain($nodes, $edges);
    while (true) {
        $cost = $supply_chain->optimize('A', 'D');
        echo "Optimized cost: " . $cost . "\n";
    }
}

main();