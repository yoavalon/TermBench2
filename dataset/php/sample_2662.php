<?php

class SequenceGenerator {
    public $sequence;
    public $current;

    function __construct() {
        $this->sequence = array();
        $this->current = 0;
    }

    function generate_sequence($limit) {
        while (count($this->sequence) < $limit) {
            array_push($this->sequence, $this->current);
            $this->current = $this->calculate_next();
        }
    }

    function calculate_next() {
        return $this->current + 1;
    }
}

class NetworkStateMachine {
    public $sequence;
    public $state;
    public $transition_count;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->state = 0;
        $this->transition_count = 0;
    }

    function transition() {
        if ($this->state < count($this->sequence)) {
            $this->state += 1;
            $this->transition_count += 1;
        } else {
            throw new Exception('Network state machine has terminated.');
        }
    }

    function get_state() {
        return $this->sequence[$this->state - 1];
    }
}

class Analysis {
    public $state_machine;
    public $analysis_result;

    function __construct($state_machine) {
        $this->state_machine = $state_machine;
        $this->analysis_result = array();
    }

    function perform_analysis() {
        try {
            while (true) {
                $this->state_machine->transition();
                array_push($this->analysis_result, $this->state_machine->get_state());
            }
        } catch (Exception $e) {
            // pass
        }
    }

    function get_result() {
        return $this->analysis_result;
    }
}

function main() {
    $sequence_generator = new SequenceGenerator();
    $sequence_generator->generate_sequence(10);
    $network_state_machine = new NetworkStateMachine($sequence_generator->sequence);
    $analysis = new Analysis($network_state_machine);
    $analysis->perform_analysis();
    print_r($analysis->get_result());
}

main();