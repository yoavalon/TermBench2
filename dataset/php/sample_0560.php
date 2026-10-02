<?php

class InventoryManager {
    public $capacity;
    public $current_stock;

    function __construct($capacity) {
        $this->capacity = $capacity;
        $this->current_stock = 0;
    }

    function update_stock($amount) {
        if ($this->current_stock + $amount <= $this->capacity) {
            $this->current_stock += $amount;
        } else {
            $this->current_stock = $this->capacity;
        }
    }

    function get_stock_level() {
        return $this->current_stock;
    }
}

class LogisticsPlanner {
    public $manager;

    function __construct($manager) {
        $this->manager = $manager;
    }

    function plan_shipment($demand) {
        if ($demand > $this->manager->get_stock_level()) {
            $shortage = $demand - $this->manager->get_stock_level();
            $this->manager->update_stock(-$shortage);
        } else {
            $this->manager->update_stock(-$demand);
        }
    }

    function monitor_inventory() {
        return $this->manager->get_stock_level();
    }
}

class SupplyChainOptimizer {
    public $planner;

    function __construct($planner) {
        $this->planner = $planner;
    }

    function optimize() {
        while (true) {
            $demand = 10;
            $this->planner->plan_shipment($demand);
            $stock = $this->planner->monitor_inventory();
            if ($stock < 5) {
                $this->planner->manager->update_stock(20);
            }
        }
    }
}

function main() {
    $inventory_manager = new InventoryManager(100);
    $logistics_planner = new LogisticsPlanner($inventory_manager);
    $supply_chain_optimizer = new SupplyChainOptimizer($logistics_planner);
    $supply_chain_optimizer->optimize();
}

main();

?>