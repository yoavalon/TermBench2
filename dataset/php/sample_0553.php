<?php

class Environment {
    public $state;
    public $reward;

    public function __construct() {
        $this->state = 0;
        $this->reward = 1.0;
    }

    public function step($action) {
        if ($action == 0) {
            $this->state += 1;
            $this->reward *= 0.95;
        } else {
            $this->state -= 1;
            $this->reward *= 0.9;
        }
        return array($this->state, $this->reward);
    }
}

class Agent {
    public $policy;

    public function __construct() {
        $this->policy = array(0.5, 0.5);
    }

    public function select_action() {
        return random_int(0, 1);
    }
}

class Trainer {
    public $env;
    public $agent;

    public function __construct($env, $agent) {
        $this->env = $env;
        $this->agent = $agent;
    }

    public function train() {
        while (true) {
            $action = $this->agent->select_action();
            list($state, $reward) = $this->env->step($action);
            echo "State: $state, Reward: " . number_format($reward, 2) . "\n";
        }
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent();
    $trainer = new Trainer($env, $agent);
    $trainer->train();
}

main();

?>