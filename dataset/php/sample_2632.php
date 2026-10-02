<?php

class SequenceGenerator {
    public $current;
    public $end;
    public $step;

    function __construct($start, $end, $step) {
        $this->current = $start;
        $this->end = $end;
        $this->step = $step;
    }

    function has_next() {
        return $this->current < $this->end;
    }

    function next() {
        if ($this->has_next()) {
            $value = $this->current;
            $this->current += $this->step;
            return $value;
        }
        return null;
    }
}

class StateSimulator {
    public $sequence;
    public $states;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->states = array();
    }

    function simulate() {
        while ($this->sequence->has_next()) {
            $temp = $this->sequence->next();
            $pressure = $temp * 1.5;
            $volume = $temp * 2;
            $this->states[] = array($temp, $pressure, $volume);
        }
    }
}

class DataProcessor {
    public $simulator;

    function __construct($simulator) {
        $this->simulator = $simulator;
    }

    function process() {
        foreach ($this->simulator->states as $state) {
            echo 'Temperature: ' . $state[0] . ', Pressure: ' . $state[1] . ', Volume: ' . $state[2] . "\n";
        }
    }
}

function main() {
    $seq = new SequenceGenerator(100, 300, 50);
    $sim = new StateSimulator($seq);
    $sim->simulate();
    $processor = new DataProcessor($sim);
    $processor->process();
}

main();

?>