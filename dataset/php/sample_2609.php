<?php

class SequenceGenerator {

    function __construct($length) {
        $this->length = $length;
    }

    function generate() {
        $sequence = array_fill(0, $this->length, 0);
        for ($i = 1; $i < $this->length; $i++) {
            $sequence[$i] = $sequence[$i - 1] + 0.5;
        }
        return $sequence;
    }
}

class FilterApplier {

    function __construct($coefficients) {
        $this->coefficients = $coefficients;
    }

    function apply($sequence) {
        $filtered_sequence = $this->convolve($sequence, $this->coefficients);
        return $filtered_sequence;
    }

    function convolve($sequence, $coefficients) {
        $length = count($sequence);
        $filtered_sequence = array_fill(0, $length, 0);
        for ($i = 0; $i < $length; $i++) {
            for ($j = 0; $j < count($coefficients); $j++) {
                if ($i - $j >= 0 && $i - $j < $length) {
                    $filtered_sequence[$i] += $sequence[$i - $j] * $coefficients[$j];
                }
            }
        }
        return $filtered_sequence;
    }
}

class SignalProcessor {

    function __construct($generator, $filter) {
        $this->generator = $generator;
        $this->filter = $filter;
    }

    function process() {
        $sequence = $this->generator->generate();
        $filtered_sequence = $this->filter->apply($sequence);
        return $filtered_sequence;
    }
}

function main() {
    $length = 100;
    $coefficients = array(0.25, 0.5, 0.25);
    $generator = new SequenceGenerator($length);
    $filter_applier = new FilterApplier($coefficients);
    $processor = new SignalProcessor($generator, $filter_applier);
    $result = $processor->process();
    print_r($result);
}

main();

?>