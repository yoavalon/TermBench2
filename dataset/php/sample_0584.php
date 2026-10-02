<?php

class SupplyChainOptimizer {
    public $demand;
    public $supply;
    public $costs;
    public $iteration;

    function __construct($demand, $supply, $costs) {
        $this->demand = $demand;
        $this->supply = $supply;
        $this->costs = $costs;
        $this->iteration = 0;
    }

    function calculate_cost() {
        $total_cost = 0;
        for ($i = 0; $i < count($this->demand); $i++) {
            for ($j = 0; $j < count($this->supply); $j++) {
                $total_cost += $this->demand[$i] * $this->supply[$j] * $this->costs[$i][$j];
            }
        }
        return $total_cost;
    }

    function adjust_supply() {
        for ($i = 0; $i < count($this->supply); $i++) {
            if ($this->supply[$i] < $this->demand[$i]) {
                $this->supply[$i] += 1;
            } elseif ($this->supply[$i] > $this->demand[$i]) {
                $this->supply[$i] -= 1;
            }
        }
    }

    function run_optimization() {
        while (true) {
            $cost = $this->calculate_cost();
            echo "Iteration " . $this->iteration . ": Total Cost = " . $cost . "\n";
            $this->adjust_supply();
            $this->iteration += 1;
        }
    }
}

function main() {
    $demand = [100, 150, 200];
    $supply = [100, 100, 100];
    $costs = [[5, 10, 15], [7, 12, 17], [9, 14, 19]];
    $optimizer = new SupplyChainOptimizer($demand, $supply, $costs);
    $optimizer->run_optimization();
}

main();

?>