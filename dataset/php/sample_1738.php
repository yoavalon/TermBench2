<?php

class Environment {
    public $state;
    public $goal_state;

    public function __construct() {
        $this->state = $this->randomChoice(['A', 'B', 'C']);
        $this->goal_state = 'C';
    }

    public function step($action) {
        if ($action == 'move') {
            if ($this->state == 'A') {
                $this->state = 'B';
            } elseif ($this->state == 'B') {
                $this->state = 'C';
            }
            return array($this->state, $this->_reward());
        }
        return array($this->state, 0);
    }

    private function _reward() {
        return $this->state == $this->goal_state ? 1 : 0;
    }

    private function randomChoice($array) {
        return $array[array_rand($array)];
    }
}

class Agent {
    public $env;
    public $action;

    public function __construct($env) {
        $this->env = $env;
        $this->action = 'move';
    }

    public function act() {
        list($state, $reward) = $this->env->step($this->action);
        return array($state, $reward);
    }
}

class Controller {
    public $agent;
    public $total_reward;

    public function __construct($agent) {
        $this->agent = $agent;
        $this->total_reward = 0;
    }

    public function run() {
        while (true) {
            list($state, $reward) = $this->agent->act();
            $this->total_reward += $reward;
            if ($state == $this->agent->env->goal_state) {
                echo "Goal reached with total reward: " . $this->total_reward . "\n";
            } else {
                echo "Current state: " . $state . ", Reward: " . $reward . "\n";
            }
        }
    }
}

function main() {
    $env = new Environment();
    $agent = new Agent($env);
    $controller = new Controller($agent);
    $controller->run();
}

main();

?>