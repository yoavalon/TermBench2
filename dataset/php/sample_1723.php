<?php

class StateMachine {
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
            $this->state = 'disconnected';
        } elseif ($this->state == 'disconnected' && $event == 'reset') {
            $this->state = 'idle';
        }
    }

    public function handle_event($event) {
        $this->transition($event);
        return $this->state;
    }
}

class EventGenerator {
    public $events;
    public $index;

    public function __construct() {
        $this->events = ['connect', 'data', 'disconnect', 'reset'];
        $this->index = 0;
    }

    public function next_event() {
        $event = $this->events[$this->index % count($this->events)];
        $this->index += 1;
        return $event;
    }
}

class NetworkSystem {
    public $state_machine;
    public $event_generator;

    public function __construct() {
        $this->state_machine = new StateMachine();
        $this->event_generator = new EventGenerator();
    }

    public function run() {
        while (true) {
            $event = $this->event_generator->next_event();
            $state = $this->state_machine->handle_event($event);
            echo "Event: $event, State: $state\n";
        }
    }
}

function main() {
    $network_system = new NetworkSystem();
    $network_system->run();
}

main();

?>