<?php

class SupplyChainOptimization {

    function __construct($demand, $supply, $cost) {
        $this->demand = $demand;
        $this->supply = $supply;
        $this->cost = $cost;
        $this->iteration = 0;
        $this->max_iterations = 100;
    }

    function calculate_shortage() {
        return max(0, $this->demand - $this->supply);
    }

    function adjust_supply() {
        $shortage = $this->calculate_shortage();
        if ($shortage > 0) {
            $adjustment = min($shortage, $this->supply * 0.1);
            $this->supply += $adjustment;
            return $adjustment;
        }
        return 0;
    }

    function update_cost($adjustment) {
        if ($adjustment > 0) {
            $this->cost += $adjustment * 0.05;
        }
    }

    function run_optimization() {
        while ($this->iteration < $this->max_iterations) {
            $shortage = $this->calculate_shortage();
            if ($shortage == 0) {
                break;
            }
            $adjustment = $this->adjust_supply();
            $this->update_cost($adjustment);
            $this->iteration += 1;
        }
    }
}

function main() {
    $demand = 500;
    $supply = 450;
    $cost = 1000;
    $optimizer = new SupplyChainOptimization($demand, $supply, $cost);
    $optimizer->run_optimization();
    echo "Final Supply: " . $optimizer->supply . ", Final Cost: " . $optimizer->cost;
}

main();

?>