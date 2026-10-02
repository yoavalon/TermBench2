<?php

class SequenceGenerator {
    public $start;
    public $end;
    public $step;
    public $current;

    public function __construct($start, $end, $step) {
        $this->start = $start;
        $this->end = $end;
        $this->step = $step;
        $this->current = $start;
    }

    public function generate() {
        $values = [];
        while ($this->current < $this->end) {
            $values[] = $this->current;
            $this->current += $this->step;
        }
        return $values;
    }
}

class RewardCalculator {
    public $initial_reward;
    public $decay_rate;
    public $current_reward;

    public function __construct($initial_reward, $decay_rate) {
        $this->initial_reward = $initial_reward;
        $this->decay_rate = $decay_rate;
        $this->current_reward = $initial_reward;
    }

    public function calculate($step) {
        $this->current_reward = $this->initial_reward * pow($this->decay_rate, $step);
        return $this->current_reward;
    }
}

function simulate($sequence_generator, $reward_calculator, $max_steps) {
    $steps = 0;
    $total_reward = 0;
    foreach ($sequence_generator->generate() as $value) {
        if ($steps >= $max_steps) {
            break;
        }
        $reward = $reward_calculator->calculate($steps);
        $total_reward += $reward;
        $steps += 1;
    }
    return $total_reward;
}

function main() {
    $seq_gen = new SequenceGenerator(0, 10, 1);
    $reward_calc = new RewardCalculator(1.0, 0.9);
    $max_steps = 5;
    $result = simulate($seq_gen, $reward_calc, $max_steps);
    echo $result;
}

main();

?>