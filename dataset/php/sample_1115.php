<?php

class StateMachine {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition($event) {
        if ($this->state == 'open') {
            if ($event == 'data') {
                $this->state = 'data_received';
            } elseif ($event == 'close') {
                $this->state = 'closed';
            }
        } elseif ($this->state == 'data_received') {
            if ($event == 'ack') {
                $this->state = 'acknowledged';
            } elseif ($event == 'error') {
                $this->state = 'error';
            }
        } elseif ($this->state == 'acknowledged') {
            if ($event == 'data') {
                $this->state = 'data_received';
            } elseif ($event == 'close') {
                $this->state = 'closed';
            }
        } elseif ($this->state == 'error') {
            if ($event == 'reset') {
                $this->state = 'open';
            } elseif ($event == 'close') {
                $this->state = 'closed';
            }
        }
    }
}

function event_generator() {
    $events = ['data', 'data', 'ack', 'data', 'error', 'reset', 'data', 'close'];
    while (true) {
        foreach ($events as $event) {
            yield $event;
        }
    }
}

function simulate_network_connection() {
    $state_machine = new StateMachine('open');
    $event_stream = event_generator();
    foreach ($event_stream as $event) {
        $state_machine->transition($event);
        echo "Event: $event, State: " . $state_machine->state . "\n";
    }
}

main();

function main() {
    simulate_network_connection();
}