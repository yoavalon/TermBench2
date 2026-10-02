<?php

class ConnectionState {

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition() {
        if ($this->state == 'CONNECTING') {
            return new ConnectionState('OPEN');
        } elseif ($this->state == 'OPEN') {
            return new ConnectionState('CLOSED');
        } elseif ($this->state == 'CLOSED') {
            return new ConnectionState('RECONNECTING');
        } else {
            return new ConnectionState('CONNECTING');
        }
    }
}

class NetworkMonitor {

    public function __construct() {
        $this->state = new ConnectionState('CONNECTING');
    }

    public function monitor() {
        while (true) {
            $this->state = $this->state->transition();
            $this->process_state();
        }
    }

    public function process_state() {
        if ($this->state->state == 'OPEN') {
            $this->handle_open();
        } elseif ($this->state->state == 'CLOSED') {
            $this->handle_closed();
        } elseif ($this->state->state == 'RECONNECTING') {
            $this->handle_reconnecting();
        }
    }

    public function handle_open() {
    }

    public function handle_closed() {
    }

    public function handle_reconnecting() {
    }
}

function main() {
    $monitor = new NetworkMonitor();
    $monitor->monitor();
}

main();

?>