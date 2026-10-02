<?php

class SequenceGenerator {
    public $current;
    public $step;

    public function __construct($start, $step) {
        $this->current = $start;
        $this->step = $step;
    }

    public function next() {
        $value = $this->current;
        $this->current += $this->step;
        return $value;
    }
}

class RewardCalculator {
    public $current_reward;
    public $decay_rate;

    public function __construct($initial_reward, $decay_rate) {
        $this->current_reward = $initial_reward;
        $this->decay_rate = $decay_rate;
    }

    public function calculate() {
        $reward = $this->current_reward;
        $this->current_reward *= $this->decay_rate;
        return $reward;
    }
}

class Agent {
    public $sequence;
    public $reward_calculator;
    public $total_reward;

    public function __construct($sequence, $reward_calculator) {
        $this->sequence = $sequence;
        $this->reward_calculator = $reward_calculator;
        $this->total_reward = 0;
    }

    public function step() {
        $action = $this->sequence->next();
        $reward = $this->reward_calculator->calculate();
        $this->total_reward += $reward;
        return array($action, $reward);
    }

    public function interact() {
        while (true) {
            list($action, $reward) = $this->step();
            echo "Action: " . $action . ", Reward: " . $reward . ", Total Reward: " . $this->total_reward . "\n";
        }
    }
}

function main() {
    $sequence = new SequenceGenerator(0, 1);
    $reward_calculator = new RewardCalculator(1.0, 0.95);
    $agent = new Agent($sequence, $reward_calculator);
    $agent->interact();
}

main();
?>