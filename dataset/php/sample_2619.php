<?php

class SequenceGenerator {
    public $current;
    public $stop;
    public $step;

    public function __construct($start, $stop, $step) {
        $this->current = $start;
        $this->stop = $stop;
        $this->step = $step;
    }

    public function generate() {
        while ($this->current < $this->stop) {
            yield $this->current;
            $this->current += $this->step;
        }
    }
}

class ThermodynamicSimulator {
    public $sequence;
    public $temperature;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->temperature = 300;
    }

    public function simulate() {
        foreach ($this->sequence->generate() as $value) {
            $this->temperature += $value * 0.1;
            yield $this->temperature;
        }
    }
}

class DataCollector {
    public $simulator;
    public $data;

    public function __construct($simulator) {
        $this->simulator = $simulator;
        $this->data = [];
    }

    public function collect() {
        foreach ($this->simulator->simulate() as $temp) {
            $this->data[] = $temp;
        }
        return $this->data;
    }
}

function main() {
    $start = 0;
    $stop = 100;
    $step = 5;
    $sequence = new SequenceGenerator($start, $stop, $step);
    $simulator = new ThermodynamicSimulator($sequence);
    $collector = new DataCollector($simulator);
    $result = $collector->collect();
    print_r($result);
}

main();