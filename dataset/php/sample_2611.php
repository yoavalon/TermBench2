<?php

class SequenceGenerator {
    public $current;
    public $increment;

    public function __construct($start, $increment) {
        $this->current = $start;
        $this->increment = $increment;
    }

    public function generate($count) {
        $sequence = [];
        for ($i = 0; $i < $count; $i++) {
            $sequence[] = $this->current;
            $this->current += $this->increment;
        }
        return $sequence;
    }
}

class SupplyChainOptimizer {
    public $demand;
    public $supply;

    public function __construct($demand, $supply) {
        $this->demand = $demand;
        $this->supply = $supply;
    }

    public function calculate_deficit() {
        $deficit = $this->demand - $this->supply;
        return max($deficit, 0);
    }

    public function optimize_supply($additional_supply) {
        $this->supply += $additional_supply;
    }
}

class SupplyChain {
    public $demand_sequence;
    public $supply_sequence;
    public $optimizer;

    public function __construct($demand_sequence, $supply_sequence) {
        $this->demand_sequence = $demand_sequence;
        $this->supply_sequence = $supply_sequence;
        $this->optimizer = new SupplyChainOptimizer(0, 0);
    }

    public function run_optimization() {
        foreach ($this->demand_sequence as $index => $demand) {
            $supply = $this->supply_sequence[$index];
            $this->optimizer->supply = $supply;
            $deficit = $this->optimizer->calculate_deficit();
            if ($deficit > 0) {
                $additional_supply_gen = new SequenceGenerator($deficit, 1);
                $additional_supply = $additional_supply_gen->generate(1)[0];
                $this->optimizer->optimize_supply($additional_supply);
            }
            echo "Demand: $demand, Supply: $supply, Deficit: $deficit, Adjusted Supply: " . $this->optimizer->supply . "\n";
        }
    }
}

function main() {
    $demand_gen = new SequenceGenerator(100, 10);
    $demand_sequence = $demand_gen->generate(10);
    $supply_gen = new SequenceGenerator(80, 5);
    $supply_sequence = $supply_gen->generate(10);
    $supply_chain = new SupplyChain($demand_sequence, $supply_sequence);
    $supply_chain->run_optimization();
}

main();

?>