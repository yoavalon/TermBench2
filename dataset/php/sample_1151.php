<?php

class ConnectionState {
    public $status;

    public function __construct($status = 'disconnected') {
        $this->status = $status;
    }

    public function connect() {
        if ($this->status == 'disconnected') {
            $this->status = 'connected';
            return 'Connection established';
        }
        return 'Already connected';
    }

    public function disconnect() {
        if ($this->status == 'connected') {
            $this->status = 'disconnected';
            return 'Connection terminated';
        }
        return 'Already disconnected';
    }

    public function toggle() {
        if ($this->status == 'connected') {
            $this->status = 'disconnected';
        } else {
            $this->status = 'connected';
        }
        return 'Status toggled to ' . $this->status;
    }
}

class NetworkHandler {
    public $state;

    public function __construct() {
        $this->state = new ConnectionState();
    }

    public function manage_connection() {
        while (true) {
            $action = $this->decide_action();
            if ($action == 'connect') {
                $this->state->connect();
            } elseif ($action == 'disconnect') {
                $this->state->disconnect();
            } elseif ($action == 'toggle') {
                $this->state->toggle();
            } else {
                break;
            }
        }
    }

    public function decide_action() {
        if ($this->state->status == 'connected') {
            return 'disconnect';
        } else {
            return 'connect';
        }
    }
}

function main() {
    $handler = new NetworkHandler();
    $handler->manage_connection();
}

main();

?>