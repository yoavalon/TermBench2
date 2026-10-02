<?php

class Environment {
    public $state;
    public $max_state;
    public $decay_rate;

    public function __construct() {
        $this->state = 0;
        $this->max_state = 100;
        $this->decay_rate = 0.99;
    }

    public function step($action) {
        $reward = $this->calculate_reward();
        $this->update_state($action);
        return array($this->state, $reward);
    }

    public function calculate_reward() {
        return 100 - $this->state * $this->decay_rate;
    }

    public function update_state($action) {
        $this->state += $action;
        if ($this->state > $this->max_state) {
            $this->state = $this->max_state;
        }
    }
}

class Agent {
    public $env;
    public $action;

    public function __construct($env) {
        $this->env = $env;
        $this->action = 1;
    }

    public function act() {
        list($state, $reward) = $this->env->step($this->action);
        return array($state, $reward);
    }
}

function simulate() {
    $env = new Environment();
    $agent = new Agent($env);
    $total_reward = 0;
    while (true) {
        list($state, $reward) = $agent->act();
        $total_reward += $reward;
        echo "State: $state, Reward: $reward, Total Reward: $total_reward\n";
    }
}

simulate();

?>