<?php

class NetworkStateMachine {
    public $state;

    public function __construct() {
        $this->state = 'idle';
    }

    public function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'idle';
        }
    }
}

function simulate_events($machine) {
    $events = ['connect', 'disconnect', 'connect', 'disconnect'];
    foreach ($events as $event) {
        $machine->transition($event);
    }
}

function main() {
    $machine = new NetworkStateMachine();
    while (true) {
        simulate_events($machine);
    }
}

main();