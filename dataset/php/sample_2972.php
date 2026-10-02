php
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
    public $generator;
    public $demand;
    public $supply;

    function __construct($generator) {
        $this->generator = $generator;
        $this->demand = 0;
        $this->supply = 0;
    }

    function update_demand($demand) {
        $this->demand = $demand;
    }

    function update_supply() {
        $this->supply = $this->generator->next();
    }

    function calculate_deficit() {
        return $this->demand - $this->supply;
    }
}

class LogisticsManager {
    public $optimizer;

    function __construct($optimizer) {
        $this->optimizer = $optimizer;
    }

    function run() {
        while (true) {
            $current_demand = $this->optimizer->demand;
            $this->optimizer->update_supply();
            $deficit = $this->optimizer->calculate_deficit();
            echo "Demand: $current_demand, Supply: {$this->optimizer->supply}, Deficit: $deficit\n";
        }
    }
}

function main() {
    $sequence = new SequenceGenerator(100, 5);
    $optimizer = new DemandOptimizer($sequence);
    $manager = new LogisticsManager($optimizer);
    $optimizer->update_demand(105);
    $manager->run();
}

main();