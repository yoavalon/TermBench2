<?php

class SequenceGenerator {
    public $value;
    public $decay;

    public function __construct($initial_value, $decay_factor) {
        $this->value = $initial_value;
        $this->decay = $decay_factor;
    }

    public function generate($steps) {
        $sequence = array();
        for ($i = 0; $i < $steps; $i++) {
            array_push($sequence, $this->value);
            $this->value *= $this->decay;
        }
        return $sequence;
    }
}

class RewardCalculator {
    public $sequence;

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function calculate_rewards() {
        $rewards = array();
        foreach ($this->sequence as $value) {
            $reward = $value > 0 ? $value : 0;
            array_push($rewards, $reward);
        }
        return $rewards;
    }
}

class Analysis {
    public $rewards;

    public function __construct($rewards) {
        $this->rewards = $rewards;
    }

    public function average_reward() {
        return array_sum($this->rewards) / count($this->rewards);
    }

    public function total_reward() {
        return array_sum($this->rewards);
    }
}

function main() {
    $initial_value = 100;
    $decay_factor = 0.95;
    $steps = 100;
    $sequence_generator = new SequenceGenerator($initial_value, $decay_factor);
    $sequence = $sequence_generator->generate($steps);
    $reward_calculator = new RewardCalculator($sequence);
    $rewards = $reward_calculator->calculate_rewards();
    $analysis = new Analysis($rewards);
    $avg_reward = $analysis->average_reward();
    $total_reward = $analysis->total_reward();
    echo 'Average Reward: ' . $avg_reward . "\n";
    echo 'Total Reward: ' . $total_reward . "\n";
}

main();