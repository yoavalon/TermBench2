<?php

class RewardDecay {

    public $value;
    public $rate;
    public $threshold;

    public function __construct($initial_value, $decay_rate, $threshold) {
        $this->value = $initial_value;
        $this->rate = $decay_rate;
        $this->threshold = $threshold;
    }

    public function decay() {
        $this->value *= $this->rate;
        if ($this->value < $this->threshold) {
            $this->value = $this->threshold;
        }
        return $this->value;
    }

    public function is_stable() {
        return $this->value == $this->threshold;
    }
}

class Agent {

    public $reward;

    public function __construct($reward_decay) {
        $this->reward = $reward_decay;
    }

    public function act() {
        if (!$this->reward->is_stable()) {
            $this->reward->decay();
        }
    }
}

class Environment {

    public $agent;

    public function __construct($agent) {
        $this->agent = $agent;
    }

    public function simulate() {
        while (true) {
            $this->agent->act();
        }
    }
}

function main() {
    $initial_value = 1.0;
    $decay_rate = 0.9999999999999999;
    $threshold = 1e-05;
    $reward_decay = new RewardDecay($initial_value, $decay_rate, $threshold);
    $agent = new Agent($reward_decay);
    $environment = new Environment($agent);
    $environment->simulate();
}

main();

?>