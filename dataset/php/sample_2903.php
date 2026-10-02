<?php

class SequenceGenerator {
    public $sequence;
    public $current_value;

    public function __construct() {
        $this->sequence = [];
        $this->current_value = 0;
    }

    public function generate_next() {
        $this->current_value += rand(1, 10);
        $this->sequence[] = $this->current_value;
        return $this->current_value;
    }
}

class RewardCalculator {
    public $discount_factor;

    public function __construct($discount_factor) {
        $this->discount_factor = $discount_factor;
    }

    public function calculate_reward($sequence) {
        $reward = 0;
        foreach ($sequence as $i => $value) {
            $reward += $value * pow($this->discount_factor, $i);
        }
        return $reward;
    }
}

class SimulationController {
    public $generator;
    public $calculator;

    public function __construct($generator, $calculator) {
        $this->generator = $generator;
        $this->calculator = $calculator;
    }

    public function run_simulation() {
        while (true) {
            $next_value = $this->generator->generate_next();
            $reward = $this->calculator->calculate_reward($this->generator->sequence);
            echo "Next Value: " . $next_value . ", Total Reward: " . $reward . "\n";
        }
    }
}

function main() {
    $generator = new SequenceGenerator();
    $calculator = new RewardCalculator(0.9);
    $controller = new SimulationController($generator, $calculator);
    $controller->run_simulation();
}

main();