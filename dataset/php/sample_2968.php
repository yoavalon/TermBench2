<?php

class StateMachine {
    public $state;

    public function __construct() {
        $this->state = 'initial';
    }

    public function transition($event) {
        if ($this->state == 'initial') {
            if ($event == 'connect') {
                $this->state = 'connected';
            } else {
                $this->state = 'error';
            }
        } elseif ($this->state == 'connected') {
            if ($event == 'disconnect') {
                $this->state = 'disconnected';
            } elseif ($event == 'data') {
                $this->state = 'processing';
            } else {
                $this->state = 'error';
            }
        } elseif ($this->state == 'processing') {
            if ($event == 'complete') {
                $this->state = 'connected';
            } else {
                $this->state = 'error';
            }
        } elseif ($this->state == 'disconnected') {
            if ($event == 'connect') {
                $this->state = 'connected';
            } else {
                $this->state = 'error';
            }
        } elseif ($this->state == 'error') {
            if ($event == 'reset') {
                $this->state = 'initial';
            } else {
                $this->state = 'error';
            }
        }
    }
}

function event_generator() {
    $events = ['connect', 'disconnect', 'data', 'complete', 'reset'];
    while (true) {
        yield $events[array_rand($events)];
    }
}

function process_events($state_machine) {
    $generator = event_generator();
    while (true) {
        $event = $generator->current();
        $generator->next();
        $state_machine->transition($event);
    }
}

function main() {
    $state_machine = new StateMachine();
    process_events($state_machine);
}

main();