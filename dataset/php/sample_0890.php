<?php

class SupplyChainOptimizer {

    public function __construct($nodes, $edges, $demand) {
        $this->nodes = $nodes;
        $this->edges = $edges;
        $this->demand = $demand;
        $this->path = array();
    }

    public function optimize() {
        $this->_find_path(0, 0, 0);
    }

    private function _find_path($current_node, $current_cost, $current_demand) {
        if ($current_node == count($this->nodes) - 1) {
            if ($current_demand == $this->demand) {
                array_push($this->path, $current_node);
                return true;
            }
            return false;
        }
        foreach ($this->edges[$current_node] as $neighbor_cost) {
            list($neighbor, $cost) = $neighbor_cost;
            if ($this->_find_path($neighbor, $current_cost + $cost, $current_demand + 1)) {
                array_unshift($this->path, $current_node);
                return true;
            }
        }
        return false;
    }
}

class DemandBalancer {

    public function __construct($nodes, $edges, $demand) {
        $this->optimizer = new SupplyChainOptimizer($nodes, $edges, $demand);
    }

    public function balance() {
        $this->optimizer->optimize();
        return $this->optimizer->path;
    }
}

function main() {
    $nodes = array(0, 1, 2, 3, 4);
    $edges = array(
        0 => array(array(1, 10), array(2, 15)),
        1 => array(array(3, 5)),
        2 => array(array(3, 10)),
        3 => array(array(4, 20)),
        4 => array()
    );
    $demand = 3;
    $balancer = new DemandBalancer($nodes, $edges, $demand);
    $result = $balancer->balance();
    print_r($result);
}

main();

?>