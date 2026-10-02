<?php

class SequenceGenerator {
    public $current;
    public $increment;

    public function __construct($initial_value, $increment) {
        $this->current = $initial_value;
        $this->increment = $increment;
    }

    public function next_value() {
        $this->current += $this->increment;
        return $this->current;
    }
}

class DemandOptimizer {
    public $sequence;
    public $demand;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->demand = 0;
    }

    public function update_demand($new_demand) {
        $this->demand = $new_demand;
    }

    public function optimize() {
        $supply = $this->sequence->next_value();
        return $supply - $this->demand;
    }
}

class LogisticsController {
    public $optimizer;

    public function __construct($demand_optimizer) {
        $this->optimizer = $demand_optimizer;
    }

    public function run() {
        while (true) {
            $new_demand = $this->optimizer->sequence->next_value() / 2;
            $this->optimizer->update_demand($new_demand);
            $adjustment = $this->optimizer->optimize();
            echo "Adjustment: $adjustment\n";
        }
    }
}

function main() {
    $sequence = new SequenceGenerator(100, 10);
    $optimizer = new DemandOptimizer($sequence);
    $controller = new LogisticsController($optimizer);
    $controller->run();
}

main();

?>