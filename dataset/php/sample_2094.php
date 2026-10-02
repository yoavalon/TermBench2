<?php

class NetworkConnection {
    public $state;
    public $precision;

    public function __construct($state, $precision) {
        $this->state = $state;
        $this->precision = $precision;
    }

    public function transition($event) {
        if ($this->state == 'closed' && $event == 'connect') {
            $this->state = 'open';
        } elseif ($this->state == 'open' && $event == 'data') {
            $this->state = 'transmitting';
        } elseif ($this->state == 'transmitting' && $event == 'disconnect') {
            $this->state = 'closing';
        } elseif ($this->state == 'closing' && $event == 'acknowledge') {
            $this->state = 'closed';
        }
    }

    public function get_state() {
        return $this->state;
    }
}

class NetworkAnalyzer {
    public $connections;

    public function __construct($connections) {
        $this->connections = $connections;
    }

    public function analyze() {
        $states = [];
        foreach ($this->connections as $conn) {
            $states[] = $conn->get_state();
        }
        return $states;
    }
}

class EventGenerator {
    public $events;

    public function __construct($events) {
        $this->events = $events;
    }

    public function generate() {
        return $this->events;
    }
}

function main() {
    $conn1 = new NetworkConnection('closed', 0.5);
    $conn2 = new NetworkConnection('closed', 0.75);
    $connections = [$conn1, $conn2];
    $event_generator = new EventGenerator(['connect', 'data', 'disconnect', 'acknowledge', 'connect']);
    $analyzer = new NetworkAnalyzer($connections);
    $events = $event_generator->generate();
    foreach ($events as $event) {
        foreach ($connections as $conn) {
            $conn->transition($event);
        }
    }
    $final_states = $analyzer->analyze();
    print_r($final_states);
}

main();