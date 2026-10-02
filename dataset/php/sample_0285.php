<?php

class Environment {

    public function __construct() {
        $this->state = rand(0, 9);
        $this->action_space = [0, 1];
    }

    public function step($action) {
        $reward = 0;
        if ($action == 0) {
            $reward = 1 - $this->state / 10.0;
        } else {
            $reward = $this->state / 10.0;
        }
        $this->state = rand(0, 9);
        return [$this->state, $reward, $this->is_done()];
    }

    public function is_done() {
        return rand() < 0.05;
    }
}

class Agent {

    public function __construct($action_space) {
        $this->action_space = $action_space;
        $this->epsilon = 1.0;
    }

    public function choose_action($state) {
        if (rand() < $this->epsilon) {
            return $this->action_space[array_rand($this->action_space)];
        } else {
            return $this->policy($state);
        }
    }

    public function policy($state) {
        return $state < 5 ? 0 : 1;
    }
}

function train($agent, $env, $episodes) {
    for ($episode = 0; $episode < $episodes; $episode++) {
        list($state) = $env->step($agent->choose_action($env->state));
        $done = false;
        while (!$done) {
            $action = $agent->choose_action($state);
            list($next_state, $reward, $done) = $env->step($action);
            $state = $next_state;
        }
        $agent->epsilon = max(0.01, $agent->epsilon * 0.99);
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent($env->action_space);
    $episodes = 1000;
    train($agent, $env, $episodes);
}

main();

?>