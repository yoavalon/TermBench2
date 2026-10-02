<?php

class NetworkConnection {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition($event) {
        if ($this->state == 'disconnected' && $event == 'connect') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'disconnected';
        } elseif ($this->state == 'connected' && $event == 'error') {
            $this->state = 'error';
        } elseif ($this->state == 'error' && $event == 'recover') {
            $this->state = 'connected';
        }
    }
}

class EventGenerator {
    private $events = ['connect', 'disconnect', 'error', 'recover'];

    public function generate() {
        return $this->events[array_rand($this->events)];
    }
}

class StateSimulator {
    private $connection;
    private $generator;

    public function __construct() {
        $this->connection = new NetworkConnection('disconnected');
        $this->generator = new EventGenerator();
    }

    public function simulate() {
        while (true) {
            $event = $this->generator->generate();
            $this->connection->transition($event);
            echo "Event: $event, State: " . $this->connection->state . "\n";
        }
    }
}

function main() {
    $simulator = new StateSimulator();
    $simulator->simulate();
}

main();
?>