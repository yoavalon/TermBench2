<?php

class SupplyChainOptimizer {
    public $nodes;
    public $edges;
    public $demand;
    public $optimized_path;

    function __construct($nodes, $edges, $demand) {
        $this->nodes = $nodes;
        $this->edges = $edges;
        $this->demand = $demand;
        $this->optimized_path = array();
    }

    function find_optimal_path($start, $end, $path = array()) {
        $path = array_merge($path, array($start));
        if ($start == $end) {
            return $path;
        }
        if (!array_key_exists($start, $this->edges)) {
            return null;
        }
        $shortest = null;
        foreach ($this->edges[$start] as $node => $value) {
            if (!in_array($node, $path)) {
                $newpath = $this->find_optimal_path($node, $end, $path);
                if ($newpath) {
                    if (!$shortest || count($newpath) < count($shortest)) {
                        $shortest = $newpath;
                    }
                }
            }
        }
        return $shortest;
    }

    function calculate_supply($path) {
        $supply = 0;
        for ($i = 0; $i < count($path) - 1; $i++) {
            $supply += $this->edges[$path[$i]][$path[$i + 1]];
        }
        return $supply;
    }

    function optimize() {
        foreach ($this->nodes as $start) {
            foreach ($this->nodes as $end) {
                if ($start != $end) {
                    $path = $this->find_optimal_path($start, $end);
                    if ($path && $this->demand <= $this->calculate_supply($path)) {
                        $this->optimized_path = $path;
                        return;
                    }
                }
            }
        }
        return null;
    }
}

function main() {
    $nodes = array('A', 'B', 'C', 'D');
    $edges = array('A' => array('B' => 10, 'C' => 5), 'B' => array('D' => 8), 'C' => array('D' => 12), 'D' => array());
    $demand = 15;
    $optimizer = new SupplyChainOptimizer($nodes, $edges, $demand);
    $optimizer->optimize();
    print_r($optimizer->optimized_path);
}

main();

?>