<?php

class ConnectionState {
    public $state;
    public $connection_id;

    public function __construct() {
        $this->state = 'idle';
        $this->connection_id = 0;
    }

    public function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'established';
            $this->connection_id += 1;
        } elseif ($this->state == 'established' && $event == 'disconnect') {
            $this->state = 'idle';
        } elseif ($this->state == 'established' && $event == 'data') {
            $this->state = 'transmitting';
        } elseif ($this->state == 'transmitting' && $event == 'complete') {
            $this->state = 'established';
        }
        return $this->state;
    }
}

class NetworkSimulator {
    public $connection;

    public function __construct() {
        $this->connection = new ConnectionState();
    }

    public function process_event($event) {
        $new_state = $this->connection->transition($event);
        return $new_state;
    }
}

class EventGenerator {
    public $events;
    public $index;

    public function __construct() {
        $this->events = ['connect', 'data', 'complete', 'disconnect'];
        $this->index = 0;
    }

    public function generate() {
        $event = $this->events[$this->index % count($this->events)];
        $this->index += 1;
        return $event;
    }
}

function main() {
    $simulator = new NetworkSimulator();
    $generator = new EventGenerator();
    while (true) {
        $event = $generator->generate();
        $new_state = $simulator->process_event($event);
        echo "Event: $event, New State: $new_state\n";
    }
}

main();
?>