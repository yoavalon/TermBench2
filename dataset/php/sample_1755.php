<?php

class Environment {
    public $state;
    public $reward;
    public $decay_rate;

    public function __construct() {
        $this->state = 0;
        $this->reward = 1.0;
        $this->decay_rate = 0.99;
    }

    public function step($action) {
        if ($action == 1) {
            $this->state += 1;
            $this->reward *= $this->decay_rate;
        } else {
            $this->state = 0;
            $this->reward = 1.0;
        }
        return array($this->state, $this->reward);
    }
}

class Agent {
    public $action;

    public function __construct() {
        $this->action = 1;
    }

    public function decide() {
        return $this->action;
    }
}

class Simulation {
    public $env;
    public $agent;

    public function __construct($env, $agent) {
        $this->env = $env;
        $this->agent = $agent;
    }

    public function run() {
        while (true) {
            $action = $this->agent->decide();
            list($state, $reward) = $this->env->step($action);
            echo "State: $state, Reward: " . number_format($reward, 4) . "\n";
        }
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent();
    $sim = new Simulation($env, $agent);
    $sim->run();
}

main();
?>