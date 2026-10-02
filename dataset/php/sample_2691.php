<?php

class SequenceSimulator {
    public $a;
    public $b;
    public $n;

    function __construct($a, $b, $n) {
        $this->a = $a;
        $this->b = $b;
        $this->n = $n;
    }

    function generate_sequence() {
        $sequence = [];
        $current = $this->a;
        for ($i = 0; $i < $this->n; $i++) {
            $sequence[] = $current;
            $current = $this->b * $current;
        }
        return $sequence;
    }

    function analyze_sequence($sequence) {
        $analysis = [
            'sum' => array_sum($sequence),
            'max' => max($sequence),
            'min' => min($sequence),
            'mean' => array_sum($sequence) / count($sequence)
        ];
        return $analysis;
    }
}

class ThermodynamicState {
    public $temperature;
    public $pressure;

    function __construct($temperature, $pressure) {
        $this->temperature = $temperature;
        $this->pressure = $pressure;
    }

    function update_state($sequence_analysis) {
        $this->temperature = $sequence_analysis['max'];
        $this->pressure = $sequence_analysis['min'];
    }
}

function main() {
    $sim = new SequenceSimulator(2, 3, 10);
    $seq = $sim->generate_sequence();
    $analysis = $sim->analyze_sequence($seq);
    $state = new ThermodynamicState(300, 1);
    $state->update_state($analysis);
    echo "Final Temperature: " . $state->temperature . ", Final Pressure: " . $state->pressure;
}

main();

?>