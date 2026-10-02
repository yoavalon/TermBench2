<?php

class SequenceGenerator {
    public $start;
    public $end;
    public $step;
    public $current;

    function __construct($start, $end, $step) {
        $this->start = $start;
        $this->end = $end;
        $this->step = $step;
        $this->current = $start;
    }

    function generate() {
        if ($this->current < $this->end) {
            $value = $this->current;
            $this->current += $this->step;
            return $value;
        }
        return null;
    }
}

class RewardCalculator {
    public $decay_rate;
    public $current_reward;

    function __construct($decay_rate) {
        $this->decay_rate = $decay_rate;
        $this->current_reward = 1.0;
    }

    function calculate() {
        $this->current_reward *= $this->decay_rate;
        return $this->current_reward;
    }
}

function process_sequence() {
    $seq_gen = new SequenceGenerator(1, 10, 1);
    $reward_calc = new RewardCalculator(0.95);
    $total_reward = 0.0;
    while (true) {
        $value = $seq_gen->generate();
        if ($value === null) {
            break;
        }
        $reward = $reward_calc->calculate();
        $total_reward += $reward;
    }
    return $total_reward;
}

function main() {
    $result = process_sequence();
    echo $result;
}

main();

?>