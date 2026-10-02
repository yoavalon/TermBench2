<?php

class SequenceGenerator {

    function __construct($length) {
        $this->length = $length;
        $this->sequence = array();
    }

    function generate_sequence() {
        for ($i = 0; $i < $this->length; $i++) {
            $this->sequence[] = $this->calculate_value($i);
        }
        return $this->sequence;
    }

    function calculate_value($index) {
        if ($index % 2 == 0) {
            return $index * $index;
        } else {
            return pow(2, $index);
        }
    }
}

class ConsensusMechanic {

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->consolidated = array();
    }

    function apply_consensus() {
        foreach ($this->sequence as $value) {
            $this->consolidated[] = $this->validate_value($value);
        }
        return $this->consolidated;
    }

    function validate_value($value) {
        if ($value > 10) {
            return $value - 5;
        } else {
            return $value * 2;
        }
    }
}

function main() {
    $length = 20;
    $generator = new SequenceGenerator($length);
    $sequence = $generator->generate_sequence();
    $mechanic = new ConsensusMechanic($sequence);
    $result = $mechanic->apply_consensus();
    print_r($result);
}

main();

?>