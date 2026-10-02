<?php

class DecayModel {
    public $value;
    public $rate;

    public function __construct($initial_value, $decay_rate) {
        $this->value = $initial_value;
        $this->rate = $decay_rate;
    }

    public function update_value() {
        $this->value *= 1 - $this->rate;
    }
}

class RewardCalculator {
    public $model;
    public $threshold = 0.01;

    public function __construct($model) {
        $this->model = $model;
    }

    public function calculate_reward() {
        if ($this->model->value < $this->threshold) {
            return 0;
        } else {
            return $this->model->value;
        }
    }
}

class Simulation {
    public $calculator;
    public $iterations;
    public $rewards = [];

    public function __construct($calculator, $iterations) {
        $this->calculator = $calculator;
        $this->iterations = $iterations;
    }

    public function run_simulation() {
        for ($i = 0; $i < $this->iterations; $i++) {
            $this->calculator->model->update_value();
            $reward = $this->calculator->calculate_reward();
            $this->rewards[] = $reward;
        }
    }
}

function main() {
    $initial_value = 1.0;
    $decay_rate = 0.1;
    $iterations = 50;
    $model = new DecayModel($initial_value, $decay_rate);
    $calculator = new RewardCalculator($model);
    $simulation = new Simulation($calculator, $iterations);
    $simulation->run_simulation();
    print_r($simulation->rewards);
}

main();

?>