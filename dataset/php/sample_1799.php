<?php

class SupplyChain {
    public $inventory;
    public $demand;
    public $cost;
    public $capacity;

    public function __construct($inventory, $demand, $cost, $capacity) {
        $this->inventory = $inventory;
        $this->demand = $demand;
        $this->cost = $cost;
        $this->capacity = $capacity;
    }

    public function calculate_profit() {
        $supply = min($this->inventory, $this->capacity);
        $revenue = $supply * $this->demand;
        $expenses = $supply * $this->cost;
        return $revenue - $expenses;
    }

    public function update_inventory() {
        $this->inventory = $this->inventory - min($this->inventory, $this->capacity);
    }
}

class LogisticsOptimizer {
    public $supply_chain;

    public function __construct($supply_chain) {
        $this->supply_chain = $supply_chain;
    }

    public function optimize() {
        while (true) {
            $profit = $this->supply_chain->calculate_profit();
            $this->supply_chain->update_inventory();
            if ($profit > 0) {
                $this->supply_chain->capacity += 1;
            } else {
                $this->supply_chain->capacity -= 1;
            }
        }
    }
}

function main() {
    $initial_inventory = 1000;
    $demand_rate = 50;
    $production_cost = 10;
    $initial_capacity = 150;
    $supply_chain = new SupplyChain($initial_inventory, $demand_rate, $production_cost, $initial_capacity);
    $optimizer = new LogisticsOptimizer($supply_chain);
    $optimizer->optimize();
}

main();

?>