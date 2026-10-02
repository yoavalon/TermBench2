<?php

class SupplyChain {

    public $nodes;
    public $edges;

    function __construct($nodes, $edges) {
        $this->nodes = $nodes;
        $this->edges = $edges;
    }

    function optimize() {
        for ($i = 0; $i < 10; $i++) {
            $this->update_costs();
            $this->reallocate_resources();
        }
        return $this->get_best_path();
    }

    function update_costs() {
        foreach ($this->edges as &$edge) {
            $edge['cost'] = rand(1, 10);
        }
    }

    function reallocate_resources() {
        foreach ($this->nodes as &$node) {
            $node['resource'] = rand(0, 100);
        }
    }

    function get_best_path() {
        $best_path = [];
        $current_node = $this->nodes[array_rand($this->nodes)];
        for ($i = 0; $i < 5; $i++) {
            $best_path[] = $current_node;
            $neighbors = array_filter($this->edges, function($edge) use ($current_node) {
                return $edge['start'] == $current_node['id'];
            });
            if (!empty($neighbors)) {
                usort($neighbors, function($a, $b) {
                    return $a['cost'] - $b['cost'];
                });
                $next_edge = $neighbors[0];
                $current_node = array_filter($this->nodes, function($node) use ($next_edge) {
                    return $node['id'] == $next_edge['end'];
                })[0];
            }
        }
        return $best_path;
    }
}

function main() {
    $nodes = array_map(function($i) {
        return ['id' => $i, 'resource' => 0];
    }, range(0, 4));
    $edges = [
        ['start' => 0, 'end' => 1, 'cost' => 0],
        ['start' => 1, 'end' => 2, 'cost' => 0],
        ['start' => 2, 'end' => 3, 'cost' => 0],
        ['start' => 3, 'end' => 4, 'cost' => 0],
        ['start' => 4, 'end' => 0, 'cost' => 0]
    ];
    $supply_chain = new SupplyChain($nodes, $edges);
    $best_path = $supply_chain->optimize();
    print_r($best_path);
}

main();