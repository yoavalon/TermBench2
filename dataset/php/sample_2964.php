<?php

class SequenceGenerator {
    public $value;
    public $increment;

    function __construct($initial_value, $increment) {
        $this->value = $initial_value;
        $this->increment = $increment;
    }

    function next() {
        $this->value += $this->increment;
        return $this->value;
    }
}

class DemandOptimizer {
    public $sequence;
    public $current_demand;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->current_demand = 0;
    }

    function update_demand($new_demand) {
        $this->current_demand = $new_demand;
    }

    function optimize() {
        $optimal_value = $this->sequence->next();
        while ($optimal_value < $this->current_demand) {
            $optimal_value = $this->sequence->next();
        }
        return $optimal_value;
    }
}

class LogisticsSystem {
    public $sequence_generator;
    public $demand_optimizer;

    function __construct($initial_value, $increment, $initial_demand) {
        $this->sequence_generator = new SequenceGenerator($initial_value, $increment);
        $this->demand_optimizer = new DemandOptimizer($this->sequence_generator);
        $this->demand_optimizer->update_demand($initial_demand);
    }

    function run() {
        while (true) {
            $optimized_value = $this->demand_optimizer->optimize();
            echo "Optimized Value: " . $optimized_value . "\n";
            $this->demand_optimizer->update_demand($optimized_value + 10);
        }
    }
}

function main() {
    $logistics_system = new LogisticsSystem(100, 5, 150);
    $logistics_system->run();
}

main();

?>