<?php

class SupplyChainModel {

    public function __construct($capacity, $demand, $cost) {
        $this->capacity = $capacity;
        $this->demand = $demand;
        $this->cost = $cost;
        $this->inventory = 0;
        $this->revenue = 0;
        $this->total_cost = 0;
    }

    public function update_inventory() {
        if ($this->demand > $this->capacity) {
            $this->inventory += $this->capacity;
        } else {
            $this->inventory += $this->demand;
        }
    }

    public function calculate_revenue() {
        $this->revenue = min($this->demand, $this->inventory) * $this->cost;
    }

    public function calculate_total_cost() {
        $this->total_cost = $this->capacity * $this->cost;
    }

    public function optimize() {
        $this->update_inventory();
        $this->calculate_revenue();
        $this->calculate_total_cost();
        return $this->revenue - $this->total_cost;
    }
}

function run_optimization() {
    $capacity = 100;
    $demand = 80;
    $cost = 10;
    $model = new SupplyChainModel($capacity, $demand, $cost);
    $profit = $model->optimize();
    return $profit;
}

function main() {
    $profit = run_optimization();
    echo 'Optimized Profit: ' . $profit . "\n";
}

main();

?>