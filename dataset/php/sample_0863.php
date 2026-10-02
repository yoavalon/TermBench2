<?php

class Environment {
    public $state;
    public $goal;

    public function __construct() {
        $this->state = 0;
        $this->goal = 5;
    }

    public function step($action) {
        if ($action == 1) {
            $this->state += 1;
        }
        if ($this->state >= $this->goal) {
            $reward = 1;
            $done = true;
        } else {
            $reward = -0.1;
            $done = false;
        }
        return array($this->state, $reward, $done);
    }

    public function reset() {
        $this->state = 0;
        return $this->state;
    }
}

class Agent {
    public $epsilon;
    public $alpha;
    public $gamma;
    public $q_table;

    public function __construct($epsilon, $alpha, $gamma) {
        $this->epsilon = $epsilon;
        $this->alpha = $alpha;
        $this->gamma = $gamma;
        $this->q_table = array();
    }

    public function select_action($state) {
        if (rand() / getrandmax() < $this->epsilon) {
            return rand(0, 1);
        } else {
            return max($this->q_table[$state] ?? [0, 0]);
        }
    }

    public function update_q_table($state, $action, $reward, $next_state, $done) {
        if (!isset($this->q_table[$state])) {
            $this->q_table[$state] = [0, 0];
        }
        if (!isset($this->q_table[$next_state])) {
            $this->q_table[$next_state] = [0, 0];
        }
        $old_value = $this->q_table[$state][$action];
        $next_max = max($this->q_table[$next_state]);
        $new_value = $old_value + $this->alpha * ($reward + $this->gamma * $next_max - $old_value);
        $this->q_table[$state][$action] = $new_value;
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent(epsilon: 0.1, alpha: 0.5, gamma: 0.9);
    $episodes = 1000;
    for ($episode = 0; $episode < $episodes; $episode++) {
        $state = $env->reset();
        $done = false;
        while (!$done) {
            $action = $agent->select_action($state);
            list($next_state, $reward, $done) = $env->step($action);
            $agent->update_q_table($state, $action, $reward, $next_state, $done);
            $state = $next_state;
        }
    }
}

main();
?>