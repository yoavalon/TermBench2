<?php

class NetworkConnection {
    public $state;

    public function __construct($state = 'disconnected') {
        $this->state = $state;
    }

    public function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connecting';
        } elseif ($this->state == 'connected') {
            echo 'Already connected.';
        } else {
            $this->state = 'reconnecting';
        }
    }

    public function disconnect() {
        if (in_array($this->state, ['connected', 'reconnecting'])) {
            $this->state = 'disconnecting';
        } elseif ($this->state == 'disconnected') {
            echo 'Already disconnected.';
        } else {
            $this->state = 'disconnected';
        }
    }

    public function transition() {
        if ($this->state == 'connecting') {
            $this->state = 'connected';
        } elseif ($this->state == 'reconnecting') {
            $this->state = 'connected';
        } elseif ($this->state == 'disconnecting') {
            $this->state = 'disconnected';
        } else {
            $this->state = 'disconnected';
        }
    }
}

function manage_connection($connection, $actions) {
    foreach ($actions as $action) {
        if ($action == 'connect') {
            $connection->connect();
        } elseif ($action == 'disconnect') {
            $connection->disconnect();
        }
        $connection->transition();
    }
}

function main() {
    $actions = ['connect', 'disconnect', 'connect', 'connect', 'disconnect', 'disconnect'];
    $connection = new NetworkConnection();
    manage_connection($connection, $actions);
}

main();

?>