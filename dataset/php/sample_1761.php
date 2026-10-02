<?php

class Environment {
    public $state = 0;
    public $goal = 10;
    public $reward_decay = 0.95;

    public function step($action) {
        if ($action == 1) {
            $this->state += 1;
        } elseif ($action == 0) {
            $this->state -= 1;
        }
        if ($this->state > $this->goal) {
            $this->state = $this->goal;
        }
        if ($this->state < 0) {
            $this->state = 0;
        }
        $reward = $this->goal - $this->state;
        return array($this->state, $reward * $this->reward_decay);
    }
}

class Agent {
    public $policy = array(0.5, 0.5);

    public function choose_action() {
        return array_rand($this->policy, 1);
    }
}

class Controller {
    public $environment;
    public $agent;

    public function __construct() {
        $this->environment = new Environment();
        $this->agent = new Agent();
    }

    public function run() {
        while (true) {
            $action = $this->agent->choose_action();
            list($state, $reward) = $this->environment->step($action);
            echo "State: " . $state . ", Reward: " . $reward . "\n";
        }
    }
}

function main() {
    $controller = new Controller();
    $controller->run();
}

main();

?>