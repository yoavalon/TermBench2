<?php

class NetworkState {
    public $state;

    public function __construct() {
        $this->state = 'idle';
    }

    public function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'active';
        } elseif ($this->state == 'active' && $event == 'disconnect') {
            $this->state = 'idle';
        } elseif ($this->state == 'active' && $event == 'data') {
            $this->state = 'processing';
        } elseif ($this->state == 'processing' && $event == 'complete') {
            $this->state = 'active';
        } elseif ($this->state == 'processing' && $event == 'error') {
            $this->state = 'active';
        }
        return $this->state;
    }
}

class EventGenerator {
    public $events;
    public $index;

    public function __construct() {
        $this->events = ['connect', 'data', 'complete', 'error', 'disconnect'];
        $this->index = 0;
    }

    public function get_event() {
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
        $this->event_generator = new EventGenerator();
    }

    public function run() {
        while (true) {
            $event = $this->event_generator->get_event();
            $new_state = $this->state_machine->transition($event);
            echo "Event: $event, New State: $new_state\n";
        }
    }
}

function main() {
    $network_system = new NetworkSystem();
    $network_system->run();
}

main();