<?php

class SupplyChain {
    public $inventory;
    public $demand;
    public $cost;

    public function __construct($inventory, $demand, $cost) {
        $this->inventory = $inventory;
        $this->demand = $demand;
        $this->cost = $cost;
    }

    public function update_inventory($supply) {
        $this->inventory += $supply;
    }

    public function meet_demand() {
        if ($this->demand > $this->inventory) {
            $shortage = $this->demand - $this->inventory;
            return array($shortage, 0);
        } else {
            $this->inventory -= $this->demand;
            return array(0, $this->demand);
        }
    }

    public function calculate_cost() {
        return $this->demand * $this->cost;
    }
}

class Optimizer {
    public $supply_chain;
    public $supply;

    public function __construct($supply_chain, $supply) {
        $this->supply_chain = $supply_chain;
        $this->supply = $supply;
    }

    public function optimize() {
        $this->supply_chain->update_inventory($this->supply);
        list($shortage, $fulfilled) = $this->supply_chain->meet_demand();
        $cost = $this->supply_chain->calculate_cost();
        return array($shortage, $fulfilled, $cost);
    }
}

function main() {
    $inventory = 100;
    $demand = 150;
    $cost = 10;
    $supply = 60;
    $supply_chain = new SupplyChain($inventory, $demand, $cost);
    $optimizer = new Optimizer($supply_chain, $supply);
    list($shortage, $fulfilled, $cost) = $optimizer->optimize();
    echo 'Shortage: ' . $shortage . ', Fulfilled: ' . $fulfilled . ', Cost: ' . $cost . "\n";
}

main();

?>