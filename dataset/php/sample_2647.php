<?php

class SequenceProcessor {

    public $sequence;
    public $length;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->length = count($sequence);
    }

    function process() {
        $transformed = $this->transform_sequence();
        return $this->analyze($transformed);
    }

    function transform_sequence() {
        $transformed = array();
        for ($i = 0; $i < $this->length; $i++) {
            $value = $this->sequence[$i];
            $transformed[] = sin($value) * cos($value);
        }
        return $transformed;
    }

    function analyze($sequence) {
        $analysis = array();
        foreach ($sequence as $value) {
            $analysis[] = round($value, 4);
        }
        return $analysis;
    }
}

function generate_sequence($n) {
    $sequence = array();
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = sqrt($i + 1);
    }
    return $sequence;
}

function main() {
    $n = 10;
    $sequence = generate_sequence($n);
    $processor = new SequenceProcessor($sequence);
    $result = $processor->process();
    print_r($result);
}

main();