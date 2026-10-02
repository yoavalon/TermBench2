<?php

class Environment {
    public $state;
    public $max_state;

    function __construct() {
        $this->state = 0;
        $this->max_state = 10;
    }

    function step($action) {
        if ($action == 1 && $this->state < $this->max_state) {
            $this->state += 1;
            $reward = 1;
        } else {
            $reward = 0;
        }
        return array($this->state, $reward);
    }
}

class Agent {
    public $learning_rate;
    public $discount_factor;
    public $q_values;

    function __construct($learning_rate, $discount_factor) {
        $this->learning_rate = $learning_rate;
        $this->discount_factor = $discount_factor;
        $this->q_values = array_fill(0, 11, 0);
    }

    function choose_action($state) {
        return $state < 10 ? 1 : 0;
    }

    function update_q_value($state, $action, $reward, $next_state) {
        $old_value = $this->q_values[$state];
        $next_max = max($this->q_values);
        $new_value = (1 - $this->learning_rate) * $old_value + $this->learning_rate * ($reward + $this->discount_factor * $next_max);
        $this->q_values[$state] = $new_value;
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent(0.1, 0.9);
    while (true) {
        $state = $env->state;
        $action = $agent->choose_action($state);
        list($next_state, $reward) = $env->step($action);
        $agent->update_q_value($state, $action, $reward, $next_state);
    }
}

main();
?>