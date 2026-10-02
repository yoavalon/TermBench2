<?php

class Environment {
    public $state;
    public $decay_rate;
    public $action_space;

    function __construct($size = 10, $decay_rate = 0.95) {
        $this->state = array_fill(0, $size, 0);
        $this->decay_rate = $decay_rate;
        $this->action_space = range(0, $size - 1);
    }

    function step($action) {
        $reward = $this->state[$action];
        $this->state[$action] *= $this->decay_rate;
        return array($this->state, $reward);
    }
}

class Agent {
    public $action_space;

    function __construct($action_space) {
        $this->action_space = $action_space;
    }

    function select_action() {
        return $this->action_space[array_rand($this->action_space)];
    }
}

class Simulator {
    public $env;
    public $agent;
    public $max_steps;

    function __construct($env, $agent, $max_steps = 100) {
        $this->env = $env;
        $this->agent = $agent;
        $this->max_steps = $max_steps;
    }

    function run() {
        for ($step = 0; $step < $this->max_steps; $step++) {
            $action = $this->agent->select_action();
            list($state, $reward) = $this->env->step($action);
            if (array_sum($state) < 0.01) {
                break;
            }
        }
        return $step + 1;
    }
}

function main() {
    $env = new Environment(10, 0.95);
    $agent = new Agent($env->action_space);
    $simulator = new Simulator($env, $agent, 100);
    $steps_to_terminate = $simulator->run();
    echo $steps_to_terminate;
}

main();
?>