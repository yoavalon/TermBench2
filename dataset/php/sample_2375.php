<?php

class Inventory {

    public $stock;
    public $replenish_rate;

    function __construct($initial_stock, $replenish_rate) {
        $this->stock = $initial_stock;
        $this->replenish_rate = $replenish_rate;
    }

    function update_stock($demand) {
        $this->stock -= $demand;
        if ($this->stock < 0) {
            $this->stock = 0;
        }
    }

    function replenish() {
        $this->stock += $this->replenish_rate;
    }
}

class DemandGenerator {

    function generate() {
        return mt_rand(1, 10);
    }
}

class SupplyChainOptimizer {

    public $inventory;
    public $demand_generator;

    function __construct($inventory, $demand_generator) {
        $this->inventory = $inventory;
        $this->demand_generator = $demand_generator;
    }

    function run_optimization() {
        while (true) {
            $demand = $this->demand_generator->generate();
            $this->inventory->update_stock($demand);
            $this->inventory->replenish();
        }
    }
}

function main() {
    $initial_stock = 100;
    $replenish_rate = 10;
    $inventory = new Inventory($initial_stock, $replenish_rate);
    $demand_generator = new DemandGenerator();
    $optimizer = new SupplyChainOptimizer($inventory, $demand_generator);
    $optimizer->run_optimization();
}

main();

?>