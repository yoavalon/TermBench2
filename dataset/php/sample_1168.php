<?php

class Environment {

    public function __construct() {
        $this->state = array_rand([0, 1, 2]);
    }

    public function step($action) {
        $reward = 0;
        if ($action == $this->state) {
            $reward = 1;
        }
        $this->state = array_rand([0, 1, 2]);
        return [$this->state, $reward];
    }
}

class Agent {

    public function __construct() {
        $this->policy = [0.33, 0.33, 0.34];
    }

    public function select_action() {
        $actions = [0, 1, 2];
        $weights = $this->policy;
        $total = array_sum($weights);
        $rand = rand() / mt_getrandmax() * $total;
        $sum = 0;
        foreach ($actions as $i => $action) {
            $sum += $weights[$i];
            if ($rand <= $sum) {
                return $action;
            }
        }
        return $actions[count($actions) - 1];
    }
}

class Simulator {

    public function __construct($environment, $agent) {
        $this->env = $environment;
        $this->agent = $agent;
        $this->total_reward = 0;
    }

    public function simulate() {
        $state = $this->env->state;
        $action = $this->agent->select_action();
        list($next_state, $reward) = $this->env->step($action);
        $this->total_reward += $reward;
        $this->simulate();
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent();
    $simulator = new Simulator($env, $agent);
    $simulator->simulate();
}

main();

?>