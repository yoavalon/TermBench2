<?php

class SequenceGenerator {
    public $size;
    public $sequence;

    public function __construct($size) {
        $this->size = $size;
        $this->sequence = array_map(function() { return rand() / getrandmax(); }, array_fill(0, $size, 0));
    }

    public function generate() {
        return $this->sequence;
    }
}

class RewardCalculator {
    public $discount_factor;

    public function __construct($discount_factor) {
        $this->discount_factor = $discount_factor;
    }

    public function calculate($sequence) {
        $reward = 0;
        foreach ($sequence as $t => $value) {
            $reward += pow($this->discount_factor, $t) * $value;
        }
        return $reward;
    }
}

class SequenceAnalyzer {
    public $reward_calculator;

    public function __construct($reward_calculator) {
        $this->reward_calculator = $reward_calculator;
    }

    public function analyze($sequence) {
        return $this->reward_calculator->calculate($sequence);
    }
}

function main() {
    $size = 10;
    $discount_factor = 0.9;
    $generator = new SequenceGenerator($size);
    $reward_calculator = new RewardCalculator($discount_factor);
    $analyzer = new SequenceAnalyzer($reward_calculator);
    $sequence = $generator->generate();
    $reward = $analyzer->analyze($sequence);
    echo 'Sequence: ' . implode(', ', $sequence) . PHP_EOL;
    echo 'Reward: ' . $reward . PHP_EOL;
}

main();

?>