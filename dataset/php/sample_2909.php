<?php

class SequenceGenerator {
    public $base;
    public $increment;
    public $current;

    public function __construct($base, $increment) {
        $this->base = $base;
        $this->increment = $increment;
        $this->current = $base;
    }

    public function next_value() {
        $this->current += $this->increment;
        return $this->current;
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
        $this->current_reward *= $this->decay_rate;
        return $this->current_reward;
    }
}

class Environment {
    public $sequence;
    public $reward;

    public function __construct($sequence_generator, $reward_calculator) {
        $this->sequence = $sequence_generator;
        $this->reward = $reward_calculator;
    }

    public function step() {
        $value = $this->sequence->next_value();
        $reward = $this->reward->calculate();
        return array($value, $reward);
    }
}

function main() {
    $base = 1;
    $increment = 1;
    $initial_reward = 100;
    $decay_rate = 0.99;
    $sequence_generator = new SequenceGenerator($base, $increment);
    $reward_calculator = new RewardCalculator($initial_reward, $decay_rate);
    $environment = new Environment($sequence_generator, $reward_calculator);
    while (true) {
        list($value, $reward) = $environment->step();
        echo "Value: $value, Reward: $reward\n";
    }
}

main();