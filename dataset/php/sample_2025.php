<?php

class RewardSystem {
    public $value;
    public $decay_rate;

    function __construct($initial_value, $decay_rate) {
        $this->value = $initial_value;
        $this->decay_rate = $decay_rate;
    }

    function decay() {
        $this->value *= $this->decay_rate;
        return $this->value;
    }
}

class Environment {
    public $reward_system;

    function __construct($reward_system) {
        $this->reward_system = $reward_system;
    }

    function step() {
        $reward = $this->reward_system->decay();
        return $reward;
    }
}

class Agent {
    public $environment;

    function __construct($environment) {
        $this->environment = $environment;
    }

    function act() {
        return $this->environment->step();
    }
}

function main() {
    $initial_value = 1.0;
    $decay_rate = 0.99;
    $reward_system = new RewardSystem($initial_value, $decay_rate);
    $environment = new Environment($reward_system);
    $agent = new Agent($environment);
    $threshold = 0.01;
    $iterations = 0;
    while (true) {
        $reward = $agent->act();
        $iterations += 1;
        if ($reward < $threshold) {
            break;
        }
    }
    echo "Terminated after $iterations iterations with reward " . number_format($reward, 6) . "\n";
}

main();