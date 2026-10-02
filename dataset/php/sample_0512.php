<?php

class NetworkState {
    public $status;
    public $connection_attempts;

    public function __construct() {
        $this->status = 'disconnected';
        $this->connection_attempts = 0;
    }

    public function connect() {
        $this->connection_attempts += 1;
        if ($this->connection_attempts < 5) {
            $this->status = 'connecting';
            $this->transition();
        } else {
            $this->status = 'failed';
        }
    }

    public function transition() {
        if ($this->status == 'connecting') {
            $this->status = 'connected';
        } elseif ($this->status == 'connected') {
            $this->status = 'disconnecting';
        } elseif ($this->status == 'disconnecting') {
            $this->status = 'disconnected';
            $this->connection_attempts = 0;
        }
    }

    public function check_status() {
        return $this->status;
    }
}

function state_manager($state) {
    while (true) {
        if ($state->check_status() == 'disconnected') {
            $state->connect();
        } elseif ($state->check_status() == 'connecting') {
            $state->transition();
        } elseif ($state->check_status() == 'connected') {
            $state->transition();
        } elseif ($state->check_status() == 'disconnecting') {
            $state->transition();
        } elseif ($state->check_status() == 'failed') {
            break;
        }
    }
}

function main() {
    $network_state = new NetworkState();
    state_manager($network_state);
}

main();

?>