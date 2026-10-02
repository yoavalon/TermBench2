<?php

class ConnectionState {

    public $state;
    public $states;

    function __construct() {
        $this->state = 'DISCONNECTED';
        $this->states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING'];
    }

    function transition($event) {
        if ($this->state == 'DISCONNECTED' && $event == 'CONNECT') {
            $this->state = 'CONNECTING';
        } elseif ($this->state == 'CONNECTING') {
            $this->state = 'CONNECTED';
        } elseif ($this->state == 'CONNECTED' && $event == 'DISCONNECT') {
            $this->state = 'DISCONNECTING';
        } elseif ($this->state == 'DISCONNECTING') {
            $this->state = 'DISCONNECTED';
        }
    }

    function current_state() {
        return $this->state;
    }
}

class EventGenerator {

    public $events;
    public $index;

    function __construct() {
        $this->events = ['CONNECT', 'DISCONNECT'];
        $this->index = 0;
    }

    function next_event() {
        $event = $this->events[$this->index];
        $this->index = ($this->index + 1) % count($this->events);
        return $event;
    }
}

class NetworkSimulator {

    public $state_machine;
    public $event_generator;

    function __construct() {
        $this->state_machine = new ConnectionState();
        $this->event_generator = new EventGenerator();
    }

    function simulate() {
        while (true) {
            $event = $this->event_generator->next_event();
            $this->state_machine->transition($event);
            echo $this->state_machine->current_state() . "\n";
        }
    }
}

function main() {
    $simulator = new NetworkSimulator();
    $simulator->simulate();
}

main();