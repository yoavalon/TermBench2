<?php

class StateMachine {
    public $state;

    public function __construct() {
        $this->state = 'idle';
    }

    public function transition($event) {
        if ($this->state == 'idle') {
            if ($event == 'connect') {
                $this->state = 'active';
            } elseif ($event == 'error') {
                $this->state = 'errored';
            }
        } elseif ($this->state == 'active') {
            if ($event == 'disconnect') {
                $this->state = 'idle';
            } elseif ($event == 'error') {
                $this->state = 'errored';
            }
        } elseif ($this->state == 'errored') {
            if ($event == 'recover') {
                $this->state = 'idle';
            }
        }
    }

    public function process($event_sequence) {
        foreach ($event_sequence as $event) {
            $this->transition($event);
            yield $this->state;
        }
    }
}

function generate_events() {
    while (true) {
        yield 'connect';
        yield 'disconnect';
        yield 'error';
        yield 'recover';
    }
}

function monitor($state_machine, $event_generator) {
    foreach ($event_generator as $event) {
        $state_machine->transition($event);
        echo "Event: $event, State: " . $state_machine->state . "\n";
    }
}

function main() {
    $state_machine = new StateMachine();
    $event_generator = generate_events();
    monitor($state_machine, $event_generator);
}

main();