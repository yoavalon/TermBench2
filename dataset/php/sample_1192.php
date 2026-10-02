<?php

class Agent {
    public $state;
    public $action;

    public function __construct($state, $action) {
        $this->state = $state;
        $this->action = $action;
    }

    public function update_state($new_state) {
        $this->state = $new_state;
    }

    public function choose_action() {
        return $this->action;
    }
}

class Environment {
    public $state;
    public $reward_function;

    public function __construct($initial_state, $reward_function) {
        $this->state = $initial_state;
        $this->reward_function = $reward_function;
    }

    public function step($action) {
        $new_state = $this->state + 1;
        $reward = $this->reward_function($new_state);
        $this->state = $new_state;
        return array($new_state, $reward);
    }
}

class Controller {
    public $agent;
    public $environment;

    public function __construct($agent, $environment) {
        $this->agent = $agent;
        $this->environment = $environment;
    }

    public function execute() {
        while (true) {
            $action = $this->agent->choose_action();
            list($new_state, $reward) = $this->environment->step($action);
            $this->agent->update_state($new_state);
        }
    }
}

function reward_decay($state) {
    return 1 / ($state + 1);
}

function main() {
    $initial_state = 0;
    $action = 0;
    $agent = new Agent($initial_state, $action);
    $environment = new Environment($initial_state, 'reward_decay');
    $controller = new Controller($agent, $environment);
    $controller->execute();
}

main();