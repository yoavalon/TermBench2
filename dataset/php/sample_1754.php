<?php

class Environment {

    public $state;
    public $rewards;

    function __construct() {
        $this->state = 0;
        $this->rewards = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    }

    function reset() {
        $this->state = 0;
        return $this->state;
    }

    function step($action) {
        if ($action == 0) {
            $reward = $this->rewards[$this->state];
            $this->state = min($this->state + 1, count($this->rewards) - 1);
            $done = false;
        } else {
            $reward = 0;
            $done = true;
        }
        return array($this->state, $reward, $done);
    }
}

class Agent {

    public $policy;

    function __construct() {
        $this->policy = [0.9, 0.1];
    }

    function select_action($state) {
        return $state < 5 ? 0 : 1;
    }
}

function simulate($env, $agent) {
    $env->reset();
    $total_reward = 0;
    $steps = 0;
    while (true) {
        $action = $agent->select_action($env->state);
        list($next_state, $reward, $done) = $env->step($action);
        $total_reward += $reward;
        $steps += 1;
        if ($done) {
            $env->reset();
        }
        if ($steps % 100 == 0) {
            echo "Step: $steps, Total Reward: $total_reward\n";
        }
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent();
    simulate($env, $agent);
}

main();

?>