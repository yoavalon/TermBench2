<?php

class Environment {

    public $num_states;
    public $num_actions;

    public function __construct($num_states, $num_actions) {
        $this->num_states = $num_states;
        $this->num_actions = $num_actions;
    }

    public function step($state, $action) {
        $reward = $this->_compute_reward($state, $action);
        $next_state = $this->_transition($state, $action);
        $done = $this->_is_done($next_state);
        return array($next_state, $reward, $done);
    }

    private function _compute_reward($state, $action) {
        return -sqrt(pow($state - $action, 2));
    }

    private function _transition($state, $action) {
        return ($state + $action) % $this->num_states;
    }

    private function _is_done($state) {
        return $state == 0;
    }
}

class Agent {

    public $num_actions;
    public $policy;

    public function __construct($num_actions) {
        $this->num_actions = $num_actions;
        $this->policy = array_fill(0, $num_actions, 1 / $num_actions);
    }

    public function select_action() {
        $cumulative_probability = 0;
        $rand = mt_rand() / mt_getrandmax();
        for ($i = 0; $i < $this->num_actions; $i++) {
            $cumulative_probability += $this->policy[$i];
            if ($rand < $cumulative_probability) {
                return $i;
            }
        }
        return $this->num_actions - 1; // In case of rounding errors
    }

    public function update_policy($state, $action, $reward) {
        $this->policy[$action] += 0.1 * ($reward - array_sum($this->policy) / count($this->policy));
    }
}

function main() {
    $num_states = 10;
    $num_actions = 5;
    $max_steps = 100;
    $gamma = 0.99;
    $env = new Environment($num_states, $num_actions);
    $agent = new Agent($num_actions);
    $state = mt_rand(0, $num_states - 1);
    for ($step = 0; $step < $max_steps; $step++) {
        $action = $agent->select_action();
        list($next_state, $reward, $done) = $env->step($state, $action);
        $agent->update_policy($state, $action, $reward);
        $state = $next_state;
        if ($done) {
            break;
        }
    }
}

main();

?>