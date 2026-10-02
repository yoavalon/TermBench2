<?php

class RewardDecay {
    public $current_reward;
    public $decay_rate;

    public function __construct($initial_reward, $decay_rate) {
        $this->current_reward = $initial_reward;
        $this->decay_rate = $decay_rate;
    }

    public function update_reward() {
        $this->current_reward *= 1 - $this->decay_rate;
    }

    public function get_current_reward() {
        return $this->current_reward;
    }
}

class Agent {
    public $reward_decay;
    public $action_count;

    public function __construct($reward_decay) {
        $this->reward_decay = $reward_decay;
        $this->action_count = 0;
    }

    public function take_action() {
        $this->action_count += 1;
        $this->reward_decay->update_reward();
    }

    public function get_reward() {
        return $this->reward_decay->get_current_reward();
    }
}

function simulate_environment($agent, $max_actions) {
    $rewards = [];
    for ($i = 0; $i < $max_actions; $i++) {
        $agent->take_action();
        $rewards[] = $agent->get_reward();
    }
    return $rewards;
}

function main() {
    $initial_reward = 1.0;
    $decay_rate = 0.01;
    $max_actions = 1000;
    $reward_decay = new RewardDecay($initial_reward, $decay_rate);
    $agent = new Agent($reward_decay);
    $rewards = simulate_environment($agent, $max_actions);
    print_r($rewards);
}

main();