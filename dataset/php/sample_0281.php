<?php

class Environment {

    public $current;
    public $goal;
    public $decay_rate;
    public $time_step;

    public function __construct($start, $goal, $decay_rate) {
        $this->current = $start;
        $this->goal = $goal;
        $this->decay_rate = $decay_rate;
        $this->time_step = 0;
    }

    public function step($action) {
        $this->current += $action;
        $this->time_step += 1;
        $reward = $this->compute_reward();
        $done = $this->is_done();
        return array($this->current, $reward, $done);
    }

    public function compute_reward() {
        $distance = abs($this->current - $this->goal);
        $reward = 1 / ($distance + 1);
        $reward *= pow(1 - $this->decay_rate, $this->time_step);
        return $reward;
    }

    public function is_done() {
        return $this->current == $this->goal || $this->time_step > 1000;
    }
}

class Agent {

    public $action_space;

    public function __construct($action_space) {
        $this->action_space = $action_space;
    }

    public function act($observation) {
        return $this->action_space->rand(0, 1) * 2 - 1;
    }
}

function run_episode($env, $agent) {
    $observation = $env->current;
    $total_reward = 0;
    $done = false;
    while (!$done) {
        $action = $agent->act($observation);
        list($observation, $reward, $done) = $env->step($action);
        $total_reward += $reward;
    }
    return $total_reward;
}

function main() {
    srand(42);
    $env = new Environment(0, 10, 0.01);
    $agent = new Agent(rand(42));
    $episode_reward = run_episode($env, $agent);
    echo 'Episode reward: ' . $episode_reward . "\n";
}

main();

?>