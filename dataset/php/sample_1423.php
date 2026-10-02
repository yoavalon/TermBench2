<?php

class SupplyChain {
    public $nodes;
    public $edges;

    function __construct($nodes, $edges) {
        $this->nodes = $nodes;
        $this->edges = $edges;
    }

    function optimize_routes() {
        $optimized_edges = array();
        foreach ($this->edges as $edge) {
            if ($edge[2] < 10) {
                array_push($optimized_edges, $edge);
            }
        }
        return $optimized_edges;
    }

    function update_inventory($orders) {
        $updated_inventory = array();
        foreach ($this->nodes as $node => $inventory) {
            foreach ($inventory as $product => $quantity) {
                if (array_key_exists($product, $orders)) {
                    $updated_inventory[$product] = $quantity - $orders[$product];
                } else {
                    $updated_inventory[$product] = $quantity;
                }
            }
        }
        return $updated_inventory;
    }
}

class LogisticsManager {
    public $supply_chain;

    function __construct($supply_chain) {
        $this->supply_chain = $supply_chain;
    }

    function process_orders($orders) {
        $optimized_routes = $this->supply_chain->optimize_routes();
        $updated_inventory = $this->supply_chain->update_inventory($orders);
        return array($optimized_routes, $updated_inventory);
    }
}

function main() {
    $nodes = array('A' => array('Product1' => 20, 'Product2' => 15), 'B' => array('Product1' => 10, 'Product2' => 25), 'C' => array('Product1' => 30, 'Product2' => 10));
    $edges = array(array('A', 'B', 5), array('B', 'C', 3), array('C', 'A', 7));
    $supply_chain = new SupplyChain($nodes, $edges);
    $logistics_manager = new LogisticsManager($supply_chain);
    $orders = array('Product1' => 10, 'Product2' => 5);
    list($optimized_routes, $updated_inventory) = $logistics_manager->process_orders($orders);
    echo 'Optimized Routes: ';
    print_r($optimized_routes);
    echo 'Updated Inventory: ';
    print_r($updated_inventory);
}

main();
?>