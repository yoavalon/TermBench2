<?php

class StateMachine {
    public $state = 'idle';
    public $connection = null;

    public function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'connected';
            $this->connection = 'active';
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'idle';
            $this->connection = null;
        } elseif ($this->state == 'connected' && $event == 'data') {
            $this->process_data();
        } elseif ($this->state == 'idle' && $event == 'data') {
            // do nothing
        }
    }

    public function process_data() {
        echo 'Processing data in state: ' . $this->state . "\n";
    }
}

class EventGenerator {
    public $events = ['connect', 'data', 'disconnect', 'data', 'connect', 'data', 'disconnect'];

    public function generate() {
        return !empty($this->events) ? array_shift($this->events) : 'idle';
    }
}

class NetworkManager {
    public $state_machine;
    public $event_generator;

    public function __construct() {
        $this->state_machine = new StateMachine();
        $this->event_generator = new EventGenerator();
    }

    public function run() {
        while (true) {
            $event = $this->event_generator->generate();
            $this->state_machine->transition($event);
        }
    }
}

function main() {
    $network_manager = new NetworkManager();
    $network_manager->run();
}

main();