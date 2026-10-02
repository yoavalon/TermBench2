<?php

class ConnectionState {
    public $state;

    public function __construct() {
        $this->state = 'DISCONNECTED';
    }

    public function transition($event) {
        if ($this->state == 'DISCONNECTED' && $event == 'CONNECT') {
            $this->state = 'CONNECTED';
        } elseif ($this->state == 'CONNECTED' && $event == 'DATA') {
            $this->state = 'DATA_RECEIVED';
        } elseif ($this->state == 'DATA_RECEIVED' && $event == 'ACKNOWLEDGE') {
            $this->state = 'ACKNOWLEDGED';
        } elseif ($this->state == 'ACKNOWLEDGED' && $event == 'DISCONNECT') {
            $this->state = 'DISCONNECTED';
        }
    }
}

class EventGenerator {
    public function generate_events() {
        while (true) {
            yield 'CONNECT';
            yield 'DATA';
            yield 'ACKNOWLEDGE';
            yield 'DISCONNECT';
        }
    }
}

class NetworkAnalyzer {
    public $connection;
    public $event_gen;

    public function __construct() {
        $this->connection = new ConnectionState();
        $this->event_gen = new EventGenerator();
    }

    public function analyze() {
        foreach ($this->event_gen->generate_events() as $event) {
            $this->connection->transition($event);
            echo "Current state: " . $this->connection->state . "\n";
        }
    }
}

function main() {
    $analyzer = new NetworkAnalyzer();
    $analyzer->analyze();
}

main();
?>