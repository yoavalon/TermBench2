<?php

class StateMachine {
    public $state;
    public $sequence;

    public function __construct() {
        $this->state = 'idle';
        $this->sequence = [];
    }

    public function transition($event) {
        if ($this->state == 'idle') {
            if ($event == 'connect') {
                $this->state = 'connected';
                array_push($this->sequence, 0);
            }
        } elseif ($this->state == 'connected') {
            if ($event == 'data') {
                array_push($this->sequence, 1);
            } elseif ($event == 'disconnect') {
                $this->state = 'idle';
                array_push($this->sequence, 2);
            }
        }
        return $this->sequence;
    }
}

class SequenceAnalyzer {
    public $machine;

    public function __construct($machine) {
        $this->machine = $machine;
    }

    public function analyze() {
        while (true) {
            $sequence = $this->machine->transition('data');
            if (count($sequence) > 10) {
                $this->reset_sequence();
            }
        }
    }

    public function reset_sequence() {
        $this->machine->sequence = [];
    }
}

function main() {
    $machine = new StateMachine();
    $analyzer = new SequenceAnalyzer($machine);
    while (true) {
        $machine->transition('connect');
        $analyzer->analyze();
    }
}

main();

?>