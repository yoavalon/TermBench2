<?php

class SupplyChainOptimization {
    public $demand_sequence;
    public $production_capacity;
    public $inventory;
    public $backlog;
    public $total_cost;
    public $production_plan;

    public function __construct($demand_sequence, $production_capacity) {
        $this->demand_sequence = $demand_sequence;
        $this->production_capacity = $production_capacity;
        $this->inventory = 0;
        $this->backlog = 0;
        $this->total_cost = 0;
        $this->production_plan = [];
    }

    public function calculate_production($demand) {
        if ($demand > $this->production_capacity) {
            $production = $this->production_capacity;
            $this->backlog += $demand - $this->production_capacity;
        } else {
            $production = $demand;
        }
        return $production;
    }

    public function update_inventory($production, $demand) {
        $this->inventory += $production - $demand;
    }

    public function update_cost($production, $demand) {
        if ($this->backlog > 0) {
            $this->total_cost += $this->backlog * 10;
        }
        $this->total_cost += $production * 5;
    }

    public function run_optimization() {
        foreach ($this->demand_sequence as $demand) {
            $production = $this->calculate_production($demand);
            array_push($this->production_plan, $production);
            $this->update_inventory($production, $demand);
            $this->update_cost($production, $demand);
        }
    }
}

function main() {
    $demand_sequence = [100, 150, 200, 250, 300, 350, 400, 450, 500, 550];
    $production_capacity = 250;
    $optimizer = new SupplyChainOptimization($demand_sequence, $production_capacity);
    $optimizer->run_optimization();
    echo 'Total Cost: ' . $optimizer->total_cost . "\n";
    echo 'Final Inventory: ' . $optimizer->inventory . "\n";
    echo 'Final Backlog: ' . $optimizer->backlog . "\n";
    echo 'Production Plan: ' . implode(', ', $optimizer->production_plan) . "\n";
}

main();

?>