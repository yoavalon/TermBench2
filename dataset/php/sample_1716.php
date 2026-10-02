<?php

class NetworkState {
    public $state;

    public function __construct() {
        $this->state = 'DISCONNECTED';
    }

    public function transition($event) {
        if ($this->state == 'DISCONNECTED' && $event == 'CONNECT') {
            $this->state = 'CONNECTED';
        } elseif ($this->state == 'CONNECTED' && $event == 'DATA_RECEIVED') {
            $this->state = 'DATA_PROCESSING';
        } elseif ($this->state == 'DATA_PROCESSING' && $event == 'DATA_PROCESSED') {
            $this->state = 'CONNECTED';
        } elseif ($this->state == 'CONNECTED' && $event == 'DISCONNECT') {
            $this->state = 'DISCONNECTED';
        }
    }
}

class NetworkEventGenerator {
    public $events;
    public $index;

    public function __construct() {
        $this->events = ['CONNECT', 'DATA_RECEIVED', 'DATA_PROCESSED', 'DISCONNECT'];
        $this->index = 0;
    }

    public function next_event() {
        $event = $this->events[$this->index];
        $this->index = ($this->index + 1) % count($this->events);
        return $event;
    }
}

class NetworkSystem {
    public $state_machine;
    public $event_generator;

    public function __construct() {
        $this->state_machine = new NetworkState();
        $this->event_generator = new NetworkEventGenerator();
    }

    public function run() {
        while (true) {
            $event = $this->event_generator->next_event();
            $this->state_machine->transition($event);
        }
    }
}

function main() {
    $system = new NetworkSystem();
    $system->run();
}

main();