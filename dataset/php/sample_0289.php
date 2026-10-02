<?php

class Environment {
    public $max_steps;
    public $current_step;

    function __construct($max_steps) {
        $this->max_steps = $max_steps;
        $this->current_step = 0;
    }

    function step($action) {
        $this->current_step += 1;
        $reward = $this->calculate_reward();
        $done = $this->current_step >= $this->max_steps;
        return array($reward, $done);
    }

    function calculate_reward() {
        return 1 - $this->current_step / $this->max_steps;
    }
}

class Agent {
    public $environment;

    function __construct($environment) {
        $this->environment = $environment;
    }

    function act() {
        $action = 0;
        list($reward, $done) = $this->environment->step($action);
        return array($reward, $done);
    }
}

function main() {
    $max_steps = 50;
    $env = new Environment($max_steps);
    $agent = new Agent($env);
    $total_reward = 0;
    while (true) {
        list($reward, $done) = $agent->act();
        $total_reward += $reward;
        if ($done) {
            break;
        }
    }
    echo $total_reward;
}

main();