<?php

class Environment {
    public $state;
    public $decay_rate;

    function __construct($start_state, $decay_rate) {
        $this->state = $start_state;
        $this->decay_rate = $decay_rate;
    }

    function update_state($action) {
        $this->state += $action * $this->decay_rate;
        return $this->state;
    }

    function get_reward() {
        return 1 / $this->state;
    }
}

class Agent {
    public $learning_rate;
    public $action;

    function __construct($learning_rate) {
        $this->learning_rate = $learning_rate;
        $this->action = 1.0;
    }

    function choose_action() {
        return $this->action;
    }

    function update_action($reward) {
        $this->action += $this->learning_rate * $reward;
    }
}

class System {
    public $env;
    public $agent;

    function __construct($env, $agent) {
        $this->env = $env;
        $this->agent = $agent;
    }

    function run() {
        while (true) {
            $action = $this->agent->choose_action();
            $new_state = $this->env->update_state($action);
            $reward = $this->env->get_reward();
            $this->agent->update_action($reward);
        }
    }
}

function main() {
    $env = new Environment(10.0, 0.01);
    $agent = new Agent(0.001);
    $system = new System($env, $agent);
    $system->run();
}

main();