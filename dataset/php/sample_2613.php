<?php

class SequenceGenerator {
    public $n;
    public $current;

    public function __construct($n) {
        $this->n = $n;
        $this->current = 0;
    }

    public function generate_sequence() {
        $sequence = [];
        while ($this->current < $this->n) {
            $sequence[] = $this->current;
            $this->current += 1;
        }
        return $sequence;
    }
}

class StateSimulator {
    public $sequence;
    public $index;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->index = 0;
    }

    public function simulate_state() {
        if ($this->index < count($this->sequence)) {
            $state = $this->sequence[$this->index];
            $this->index += 1;
            return $state;
        }
        return null;
    }
}

function main() {
    $n = 10;
    $generator = new SequenceGenerator($n);
    $sequence = $generator->generate_sequence();
    $simulator = new StateSimulator($sequence);
    while (true) {
        $state = $simulator->simulate_state();
        if ($state === null) {
            break;
        }
        echo "Simulating state: $state\n";
    }
}

main();

?>