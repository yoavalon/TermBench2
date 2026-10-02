<?php

class Environment {

    public function __construct($size) {
        $this->state = array_fill(0, $size, 0);
    }

    public function reset() {
        $this->state = array_fill(0, count($this->state), 0);
        return $this->state;
    }

    public function step($action) {
        $reward = mt_rand() / mt_getrandmax() * 2 - 1; // Random normal distribution
        $this->state[$action] += 1;
        $done = false;
        foreach ($this->state as $s) {
            if ($s > 10) {
                $done = true;
                break;
            }
        }
        return array($this->state, $reward, $done);
    }
}

class Agent {

    public function __construct($action_space) {
        $this->action_space = $action_space;
    }

    public function choose_action() {
        return $this->action_space[array_rand($this->action_space)];
    }
}

function train_agent($env, $agent, $episodes, $decay_rate) {
    $rewards = array();
    for ($episode = 0; $episode < $episodes; $episode++) {
        $state = $env->reset();
        $total_reward = 0;
        for ($step = 0; $step < 100; $step++) {
            $action = $agent->choose_action();
            list($state, $reward, $done) = $env->step($action);
            $total_reward += $reward;
            if ($done) {
                break;
            }
        }
        $rewards[] = $total_reward;
        if ($episode > 0 && $episode % 10 == 0) {
            $rewards = array_map(function($r) use ($decay_rate) {
                return $r * $decay_rate;
            }, $rewards);
        }
    }
    return $rewards;
}

function main() {
    $env_size = 5;
    $action_space = range(0, $env_size - 1);
    $env = new Environment($env_size);
    $agent = new Agent($action_space);
    $episodes = 50;
    $decay_rate = 0.9;
    train_agent($env, $agent, $episodes, $decay_rate);
}

main();

?>