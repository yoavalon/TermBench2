<?php

class SequenceGenerator {
    public $sequence;

    function __construct() {
        $this->sequence = [rand(1, 10)];
    }

    function generate() {
        $last_value = end($this->sequence);
        $next_value = rand($last_value - 2, $last_value + 2);
        array_push($this->sequence, $next_value);
        return $next_value;
    }
}

class RewardDecayer {
    public $base_reward;
    public $decay_factor;
    public $current_reward;

    function __construct($base_reward) {
        $this->base_reward = $base_reward;
        $this->decay_factor = 0.95;
        $this->current_reward = $base_reward;
    }

    function decay() {
        $this->current_reward *= $this->decay_factor;
        return $this->current_reward;
    }
}

class Analysis {
    public $generator;
    public $decayer;

    function __construct($generator, $decayer) {
        $this->generator = $generator;
        $this->decayer = $decayer;
    }

    function evaluate() {
        $total_reward = 0;
        while (true) {
            $value = $this->generator->generate();
            $reward = $this->decayer->decay();
            $total_reward += $reward;
            echo "Value: $value, Reward: " . number_format($reward, 2) . ", Total Reward: " . number_format($total_reward, 2) . "\n";
        }
    }
}

function main() {
    $generator = new SequenceGenerator();
    $decayer = new RewardDecayer(100);
    $analysis = new Analysis($generator, $decayer);
    $analysis->evaluate();
}

main();

?>