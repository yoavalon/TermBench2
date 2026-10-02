<?php

class Environment {
    public $state;
    public $max_steps;
    public $step_count;

    public function __construct($max_steps) {
        $this->state = 0;
        $this->max_steps = $max_steps;
        $this->step_count = 0;
    }

    public function reset() {
        $this->state = 0;
        $this->step_count = 0;
    }

    public function step($action) {
        $this->step_count += 1;
        $reward = $this->calculate_reward($action);
        $this->state = $this->update_state($action);
        $done = $this->step_count >= $this->max_steps;
        return array($this->state, $reward, $done);
    }

    public function calculate_reward($action) {
        return $action == 1 ? 1 : -1;
    }

    public function update_state($action) {
        return ($this->state + $action) % 10;
    }
}

class Agent {
    public $env;
    public $policy;

    public function __construct($env) {
        $this->env = $env;
        $this->policy = array(0 => 1, 1 => 0, 2 => 1, 3 => 0, 4 => 1, 5 => 0, 6 => 1, 7 => 0, 8 => 1, 9 => 0);
    }

    public function act($state) {
        return $this->policy[$state];
    }
}

function run_episode($env, $agent) {
    $env->reset();
    $done = false;
    $total_reward = 0;
    while (!$done) {
        $state = $env->state;
        $action = $agent->act($state);
        list($state, $reward, $done) = $env->step($action);
        $total_reward += $reward;
    }
    return $total_reward;
}

function main() {
    $env = new Environment(20);
    $agent = new Agent($env);
    $total_episodes = 10;
    $episode_rewards = array();
    for ($i = 0; $i < $total_episodes; $i++) {
        $episode_reward = run_episode($env, $agent);
        array_push($episode_rewards, $episode_reward);
    }
    echo 'Episode rewards: ' . implode(', ', $episode_rewards) . PHP_EOL;
}

main();

?>