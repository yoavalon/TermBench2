<?php

class StateMachine {
    public $state;

    public function __construct() {
        $this->state = 0;
    }

    public function transition($input_value) {
        if ($this->state == 0) {
            if ($input_value == 0) {
                $this->state = 1;
            } elseif ($input_value == 1) {
                $this->state = 2;
            }
        } elseif ($this->state == 1) {
            if ($input_value == 0) {
                $this->state = 0;
            } elseif ($input_value == 1) {
                $this->state = 3;
            }
        } elseif ($this->state == 2) {
            if ($input_value == 0) {
                $this->state = 3;
            } elseif ($input_value == 1) {
                $this->state = 1;
            }
        } elseif ($this->state == 3) {
            if ($input_value == 0) {
                $this->state = 2;
            } elseif ($input_value == 1) {
                $this->state = 0;
            }
        }
    }

    public function get_state() {
        return $this->state;
    }
}

function generate_sequence() {
    $sequence = [];
    $current_value = 0;
    while (true) {
        $sequence[] = $current_value;
        $current_value = ($current_value + 1) % 2;
        yield $sequence;
    }
}

function process_sequence($state_machine, $sequence_generator) {
    foreach ($sequence_generator as $sequence) {
        foreach ($sequence as $value) {
            $state_machine->transition($value);
            yield $state_machine->get_state();
        }
    }
}

function main() {
    $state_machine = new StateMachine();
    $sequence_generator = generate_sequence();
    $state_generator = process_sequence($state_machine, $sequence_generator);
    foreach ($state_generator as $state) {
        echo $state . "\n";
    }
}

main();

?>