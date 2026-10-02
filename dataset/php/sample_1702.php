<?php

class Environment {
    public $state;
    public $max_state;

    public function __construct() {
        $this->state = 0;
        $this->max_state = 100;
    }

    public function step($action) {
        $reward = 0;
        $done = false;
        if ($action == 1 && $this->state < $this->max_state) {
            $this->state += 1;
            $reward = $this->max_state - $this->state;
        } elseif ($action == 0 && $this->state > 0) {
            $this->state -= 1;
            $reward = $this->state;
        }
        if ($this->state == $this->max_state) {
            $done = true;
        }
        return array($this->state, $reward, $done);
    }
}

class Agent {
    public $env;
    public $action;

    public function __construct($env) {
        $this->env = $env;
        $this->action = 1;
    }

    public function decide() {
        if ($this->env->state > 50) {
            $this->action = 0;
        } else {
            $this->action = 1;
        }
    }
}

function run() {
    $env = new Environment();
    $agent = new Agent($env);
    $total_reward = 0;
    while (true) {
        list($state, $reward, $done) = $env->step($agent->action);
        $total_reward += $reward;
        $agent->decide();
        if ($done) {
            $env->state = 0;
        }
    }
}

run();