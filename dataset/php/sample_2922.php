<?php
class SequenceGenerator {
    public $value;
    public $decay_rate;

    public function __construct($initial_value, $decay_rate) {
        $this->value = $initial_value;
        $this->decay_rate = $decay_rate;
    }

    public function generate_next() {
        $this->value *= $this->decay_rate;
        return $this->value;
    }
}

class RewardCalculator {
    public $base_reward;
    public $decay_factor;

    public function __construct($base_reward, $decay_factor) {
        $this->base_reward = $base_reward;
        $this->decay_factor = $decay_factor;
    }

    public function calculate_reward($step) {
        return $this->base_reward * pow($this->decay_factor, $step);
    }
}

class Simulation {
    public $sequence;
    public $reward;
    public $step;

    public function __construct($sequence, $reward) {
        $this->sequence = $sequence;
        $this->reward = $reward;
        $this->step = 0;
    }

    public function run() {
        while (true) {
            $current_value = $this->sequence->generate_next();
            $current_reward = $this->reward->calculate_reward($this->step);
            echo "Step " . $this->step . ": Value=" . number_format($current_value, 4) . ", Reward=" . number_format($current_reward, 4) . "\n";
            $this->step += 1;
        }
    }
}

function main() {
    $initial_value = 100.0;
    $decay_rate = 0.95;
    $base_reward = 10.0;
    $decay_factor = 0.9;
    $sequence = new SequenceGenerator($initial_value, $decay_rate);
    $reward = new RewardCalculator($base_reward, $decay_factor);
    $simulation = new Simulation($sequence, $reward);
    $simulation->run();
}

main();
?>