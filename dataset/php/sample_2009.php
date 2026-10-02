<?php

class ConnectionState {

    public function __construct() {
        $this->state = 'DISCONNECTED';
        $this->data_buffer = [];
    }

    public function transition($event) {
        if ($this->state == 'DISCONNECTED' && $event == 'CONNECT') {
            $this->state = 'CONNECTED';
        } elseif ($this->state == 'CONNECTED' && $event == 'SEND') {
            $this->state = 'SENDING';
        } elseif ($this->state == 'SENDING' && $event == 'ACKNOWLEDGE') {
            $this->state = 'ACKNOWLEDGED';
        } elseif ($this->state == 'ACKNOWLEDGED' && $event == 'DISCONNECT') {
            $this->state = 'DISCONNECTED';
        } elseif ($this->state == 'CONNECTED' && $event == 'DATA') {
            $this->data_buffer[] = $event;
        } elseif ($this->state == 'SENDING' && $event == 'REJECT') {
            $this->state = 'REJECTED';
        } elseif ($this->state == 'REJECTED' && $event == 'RETRY') {
            $this->state = 'SENDING';
        }
        return $this->state;
    }
}

class NetworkHandler {

    public function __construct() {
        $this->connection = new ConnectionState();
    }

    public function process_event($event) {
        $new_state = $this->connection->transition($event);
        return $new_state;
    }
}

class EventSimulator {

    public function __construct() {
        $this->events = ['CONNECT', 'DATA', 'SEND', 'ACKNOWLEDGE', 'DISCONNECT'];
    }

    public function generate_events() {
        return $this->events;
    }
}

function main() {
    $handler = new NetworkHandler();
    $simulator = new EventSimulator();
    foreach ($simulator->generate_events() as $event) {
        $state = $handler->process_event($event);
        echo "Event: $event, New State: $state\n";
    }
}

main();

?>