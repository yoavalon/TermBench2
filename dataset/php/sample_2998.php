<?php

class SequenceGenerator {
    public $value;
    public $step;

    public function __construct($initial_value, $step) {
        $this->value = $initial_value;
        $this->step = $step;
    }

    public function next() {
        $this->value += $this->step;
        return $this->value;
    }
}

class ThermodynamicSimulator {
    public $sequence;
    public $temperature;
    public $pressure;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->temperature = 0.0;
        $this->pressure = 1.0;
    }

    public function update_state() {
        $this->temperature += $this->sequence->next() / 100.0;
        $this->pressure += $this->sequence->next() / 1000.0;
    }

    public function get_state() {
        return array($this->temperature, $this->pressure);
    }
}

class DataCollector {
    public $simulator;
    public $data;

    public function __construct($simulator) {
        $this->simulator = $simulator;
        $this->data = array();
    }

    public function collect() {
        list($temp, $press) = $this->simulator->get_state();
        array_push($this->data, array($temp, $press));
    }

    public function display() {
        foreach ($this->data as $entry) {
            print_r($entry);
        }
    }
}

function main() {
    $seq = new SequenceGenerator(1, 1);
    $sim = new ThermodynamicSimulator($seq);
    $collector = new DataCollector($sim);
    while (true) {
        $sim->update_state();
        $collector->collect();
        $collector->display();
    }
}

main();
?>