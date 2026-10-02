<?php

class SequenceSimulator {
    public $a;
    public $b;
    public $n;
    public $sequence;

    function __construct($a, $b, $n) {
        $this->a = $a;
        $this->b = $b;
        $this->n = $n;
        $this->sequence = array();
    }

    function generate_sequence() {
        for ($i = 0; $i < $this->n; $i++) {
            $value = $this->a + $i * $this->b;
            array_push($this->sequence, $value);
        }
    }

    function calculate_thermodynamic_states() {
        $states = array();
        foreach ($this->sequence as $value) {
            $state = exp(-$value);
            array_push($states, $state);
        }
        return $states;
    }
}

class DataAnalyzer {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function average() {
        return array_sum($this->data) / count($this->data);
    }

    function max_value() {
        return max($this->data);
    }

    function min_value() {
        return min($this->data);
    }
}

function main() {
    $a = 0;
    $b = 0.1;
    $n = 100;
    $simulator = new SequenceSimulator($a, $b, $n);
    $simulator->generate_sequence();
    $states = $simulator->calculate_thermodynamic_states();
    $analyzer = new DataAnalyzer($states);
    echo 'Average State: ' . $analyzer->average() . "\n";
    echo 'Max State: ' . $analyzer->max_value() . "\n";
    echo 'Min State: ' . $analyzer->min_value() . "\n";
}

main();