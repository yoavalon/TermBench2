<?php

class SequenceGenerator {
    public $a;
    public $b;
    public $current;

    public function __construct($a, $b) {
        $this->a = $a;
        $this->b = $b;
        $this->current = $a;
    }

    public function next() {
        $this->current += $this->b;
        return $this->current;
    }
}

class InventoryOptimizer {
    public $stock;
    public $demand_sequence;
    public $current_demand;

    public function __construct($initial_stock, $demand_sequence) {
        $this->stock = $initial_stock;
        $this->demand_sequence = $demand_sequence;
        $this->current_demand = 0;
    }

    public function update_stock($supply) {
        $this->stock += $supply;
    }

    public function process_demand() {
        $this->current_demand = $this->demand_sequence->next();
        if ($this->stock >= $this->current_demand) {
            $this->stock -= $this->current_demand;
        } else {
            $this->stock = 0;
        }
    }
}

class SupplyChainSimulator {
    public $inventory_optimizer;
    public $supply_sequence;

    public function __construct($initial_stock, $demand_a, $demand_b, $supply_a, $supply_b) {
        $this->inventory_optimizer = new InventoryOptimizer($initial_stock, new SequenceGenerator($demand_a, $demand_b));
        $this->supply_sequence = new SequenceGenerator($supply_a, $supply_b);
    }

    public function run() {
        while (true) {
            $supply = $this->supply_sequence->next();
            $this->inventory_optimizer->update_stock($supply);
            $this->inventory_optimizer->process_demand();
        }
    }
}

function main() {
    $initial_stock = 100;
    $demand_a = 10;
    $demand_b = 5;
    $supply_a = 20;
    $supply_b = 10;
    $simulator = new SupplyChainSimulator($initial_stock, $demand_a, $demand_b, $supply_a, $supply_b);
    $simulator->run();
}

main();

?>