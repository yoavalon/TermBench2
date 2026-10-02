<?php

class Environment {

    public $state;
    public $terminal_state;
    public $rewards;

    function __construct() {
        $this->state = 0;
        $this->terminal_state = 10;
        $this->rewards = range(1, $this->terminal_state);
    }

    function step($action) {
        if ($this->state + $action > $this->terminal_state) {
            return array($this->state, 0, true);
        }
        $this->state += $action;
        $reward = $this->rewards[$this->state - 1];
        return array($this->state, $reward, $this->state == $this->terminal_state);
    }
}

class Agent {

    public $alpha;
    public $gamma;
    public $q_table;

    function __construct($alpha, $gamma) {
        $this->alpha = $alpha;
        $this->gamma = $gamma;
        $this->q_table = array_fill(0, 11, 0);
    }

    function choose_action($state) {
        if (rand() / getrandmax() > 0.5) {
            return 1;
        } else {
            return 2;
        }
    }

    function learn($state, $action, $reward, $next_state) {
        $td_target = $reward + $this->gamma * max(array_slice($this->q_table, $next_state));
        $td_error = $td_target - $this->q_table[$state + $action - 1];
        $this->q_table[$state + $action - 1] += $this->alpha * $td_error;
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent(0.1, 0.99);
    $episodes = 1000;
    for ($i = 0; $i < $episodes; $i++) {
        $state = $env->state;
        while (true) {
            $action = $agent->choose_action($state);
            list($next_state, $reward, $done) = $env->step($action);
            $agent->learn($state, $action, $reward, $next_state);
            $state = $next_state;
            if ($done) {
                break;
            }
        }
    }
}

main();

?>