<?php

class ConnectionState {

    public function __construct() {
        $this->state = 'disconnected';
    }

    public function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connected';
            return true;
        }
        return false;
    }

    public function disconnect() {
        if ($this->state == 'connected') {
            $this->state = 'disconnected';
            return true;
        }
        return false;
    }

    public function is_connected() {
        return $this->state == 'connected';
    }
}

class NetworkManager {

    public function __construct($state) {
        $this->state = $state;
    }

    public function attempt_connection() {
        if (!$this->state->is_connected()) {
            $this->state->connect();
        } else {
            $this->state->disconnect();
        }
    }

    public function monitor() {
        for ($i = 0; $i < 10; $i++) {
            $this->attempt_connection();
            if ($this->state->is_connected()) {
                break;
            }
        }
    }
}

function main() {
    $state = new ConnectionState();
    $manager = new NetworkManager($state);
    $manager->monitor();
}

main();

?>