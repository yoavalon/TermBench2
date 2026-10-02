<?php

class ThermodynamicSimulation {
    public $state;
    public $rate;
    public $threshold;

    public function __construct($initial_state, $rate, $threshold) {
        $this->state = $initial_state;
        $this->rate = $rate;
        $this->threshold = $threshold;
    }

    public function update_state() {
        $this->state += $this->rate;
        if ($this->state > $this->threshold) {
            $this->state = $this->threshold - ($this->state - $this->threshold);
        }
    }
}

class SequenceGenerator {
    public $value;
    public $increment;

    public function __construct($start, $increment) {
        $this->value = $start;
        $this->increment = $increment;
    }

    public function next_value() {
        $this->value += $this->increment;
        return $this->value;
    }
}

class Analysis {
    public $simulation;
    public $generator;

    public function __construct($sim, $gen) {
        $this->simulation = $sim;
        $this->generator = $gen;
    }

    public function run() {
        while (true) {
            $this->simulation->update_state();
            $val = $this->generator->next_value();
            echo 'State: ' . $this->simulation->state . ', Value: ' . $val . "\n";
        }
    }
}

function main() {
    $sim = new ThermodynamicSimulation(10, 2, 20);
    $gen = new SequenceGenerator(0, 1);
    $analysis = new Analysis($sim, $gen);
    $analysis->run();
}

main();