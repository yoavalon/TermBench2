<?php

class Environment {
    public $state;
    public $reward;

    function __construct() {
        $this->state = 0;
        $this->reward = 1.0;
    }

    function step($action) {
        if ($action == 0) {
            $this->state += 1;
            $this->reward *= 0.95;
        } else {
            $this->state -= 1;
            $this->reward *= 0.9;
        }
        if ($this->state > 10) {
            return array($this->state, 0, true);
        } elseif ($this->state < 0) {
            return array($this->state, 0, true);
        } else {
            return array($this->state, $this->reward, false);
        }
    }
}

class Agent {
    public $policy;

    function __construct() {
        $this->policy = array(0.5, 0.5);
    }

    function choose_action() {
        return array_rand($this->policy, 1);
    }
}

function simulate() {
    $env = new Environment();
    $agent = new Agent();
    $done = false;
    while (!$done) {
        $action = $agent->choose_action();
        list($_, $reward, $done) = $env->step($action);
    }
    return $reward;
}

function main() {
    $results = array();
    for ($i = 0; $i < 100; $i++) {
        $result = simulate();
        array_push($results, $result);
    }
    echo array_sum($results) / count($results);
}

main();

?>