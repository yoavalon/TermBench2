<?php

class NetworkState {
    public $state;

    public function __construct() {
        $this->state = 'idle';
    }

    public function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $event == 'data') {
            $this->state = 'transmitting';
        } elseif ($this->state == 'transmitting' && $event == 'disconnect') {
            $this->state = 'idle';
        } else {
            $this->state = 'error';
        }
    }
}

class NetworkManager {
    public $state_machine;

    public function __construct() {
        $this->state_machine = new NetworkState();
    }

    public function process_events($events) {
        foreach ($events as $event) {
            $this->state_machine->transition($event);
            if ($this->state_machine->state == 'error') {
                return false;
            }
        }
        return true;
    }
}

class EventGenerator {
    public $events;

    public function __construct() {
        $this->events = ['connect', 'data', 'disconnect'];
    }

    public function generate() {
        return $this->events;
    }
}

function main() {
    $event_gen = new EventGenerator();
    $network_mgr = new NetworkManager();
    $events = $event_gen->generate();
    $success = $network_mgr->process_events($events);
    echo $success;
}

main();

?>