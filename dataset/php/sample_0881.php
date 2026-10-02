<?php

class ConnectionState {
    public $state;

    public function __construct() {
        $this->state = 'disconnected';
    }

    public function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connecting';
            return $this->connecting();
        }
        return 'already connected';
    }

    public function connecting() {
        if ($this->state == 'connecting') {
            $this->state = 'connected';
            return $this->connected();
        }
        return 'connection failed';
    }

    public function connected() {
        if ($this->state == 'connected') {
            $this->state = 'disconnecting';
            return $this->disconnecting();
        }
        return 'connection lost';
    }

    public function disconnecting() {
        if ($this->state == 'disconnecting') {
            $this->state = 'disconnected';
            return 'disconnected';
        }
        return 'disconnection failed';
    }
}

function simulate_connections() {
    $conn = new ConnectionState();
    $states = ['connect', 'connect', 'disconnect', 'connect', 'disconnect'];
    $results = [];
    foreach ($states as $action) {
        if ($action == 'connect') {
            $results[] = $conn->connect();
        } elseif ($action == 'disconnect') {
            $results[] = $conn->disconnecting();
        }
    }
    return $results;
}

function main() {
    $results = simulate_connections();
    foreach ($results as $result) {
        echo $result . "\n";
    }
}

main();

?>