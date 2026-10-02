<?php

class SequenceGenerator {
    public $current_value;
    public $step;
    public $decay_factor;

    public function __construct($start, $step, $decay_factor) {
        $this->current_value = $start;
        $this->step = $step;
        $this->decay_factor = $decay_factor;
    }

    public function generate_next() {
        $this->current_value += $this->step;
        $this->step *= $this->decay_factor;
        return $this->current_value;
    }
}

class RewardEvaluator {
    public $threshold;

    public function __construct($threshold) {
        $this->threshold = $threshold;
    }

    public function evaluate($value) {
        return max(0, $value - $this->threshold);
    }
}

class NonTerminatingSimulation {
    public $sequence_gen;
    public $reward_eval;

    public function __construct($sequence_gen, $reward_eval) {
        $this->sequence_gen = $sequence_gen;
        $this->reward_eval = $reward_eval;
    }

    public function run() {
        $total_reward = 0;
        while (true) {
            $next_value = $this->sequence_gen->generate_next();
            $reward = $this->reward_eval->evaluate($next_value);
            $total_reward += $reward;
            echo "Value: $next_value, Reward: $reward, Total Reward: $total_reward\n";
        }
    }
}

function main() {
    $start_value = rand(1, 10);
    $step_size = mt_rand() / mt_getrandmax() * (2.0 - 0.5) + 0.5;
    $decay_factor = mt_rand() / mt_getrandmax() * (0.99 - 0.9) + 0.9;
    $threshold = rand(5, 15);
    $seq_gen = new SequenceGenerator($start_value, $step_size, $decay_factor);
    $reward_eval = new RewardEvaluator($threshold);
    $simulation = new NonTerminatingSimulation($seq_gen, $reward_eval);
    $simulation->run();
}

main();