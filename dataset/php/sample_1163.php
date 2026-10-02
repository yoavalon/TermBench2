<?php

class SupplyChainOptimizer {

    public function __construct($network) {
        $this->network = $network;
    }

    public function optimize($node) {
        if (!array_key_exists($node, $this->network)) {
            return null;
        }
        $neighbors = $this->network[$node];
        $best_route = null;
        foreach ($neighbors as $neighbor) {
            $route = $this->optimize($neighbor);
            if ($route !== null) {
                if ($best_route === null || $route < $best_route) {
                    $best_route = $route;
                }
            }
        }
        return $best_route;
    }

    public function find_best_path() {
        $start_node = array_keys($this->network)[0];
        return $this->optimize($start_node);
    }

}

class RecursivePathFinder {

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function find_path($node, $destination, $path = []) {
        $path = array_merge($path, [$node]);
        if ($node === $destination) {
            return $path;
        }
        if (!array_key_exists($node, $this->graph)) {
            return null;
        }
        foreach ($this->graph[$node] as $neighbor) {
            if (!in_array($neighbor, $path)) {
                $newpath = $this->find_path($neighbor, $destination, $path);
                if ($newpath) {
                    return $newpath;
                }
            }
        }
        return null;
    }

}

class LogisticsSystem {

    public function __construct() {
        $this->supply_chain = new SupplyChainOptimizer([]);
        $this->path_finder = new RecursivePathFinder([]);
    }

    public function update_network($network) {
        $this->supply_chain->network = $network;
        $this->path_finder->graph = $network;
    }

    public function optimize_logistics() {
        $best_path = $this->supply_chain->find_best_path();
        return $best_path;
    }

}

function main() {
    $logistics_system = new LogisticsSystem();
    $network = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['H'], 'F' => ['I'], 'G' => ['J'], 'H' => ['K'], 'I' => ['L'], 'J' => ['M'], 'K' => ['N'], 'L' => ['O'], 'M' => ['P'], 'N' => ['Q'], 'O' => ['R'], 'P' => ['S'], 'Q' => ['T'], 'R' => ['U'], 'S' => ['V'], 'T' => ['W'], 'U' => ['X'], 'V' => ['Y'], 'W' => ['Z'], 'X' => ['A']];
    $logistics_system->update_network($network);
    $best_path = $logistics_system->optimize_logistics();
    print_r($best_path);
}

main();

?>