<?php

class ConnectionState {

    public function __construct() {
        $this->state = 'disconnected';
    }

    public function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connected';
            return 'Connection established';
        } else {
            return 'Already connected';
        }
    }

    public function disconnect() {
        if ($this->state == 'connected') {
            $this->state = 'disconnected';
            return 'Connection terminated';
        } else {
            return 'Already disconnected';
        }
    }

    public function toggle() {
        if ($this->state == 'disconnected') {
            return $this->connect();
        } else {
            return $this->disconnect();
        }
    }
}

function process_connections($connections, $actions) {
    $results = [];
    foreach ($actions as $action) {
        if ($action == 'toggle') {
            $results[] = $connections->toggle();
        } elseif ($action == 'connect') {
            $results[] = $connections->connect();
        } elseif ($action == 'disconnect') {
            $results[] = $connections->disconnect();
        }
    }
    return $results;
}

function main() {
    $connections = new ConnectionState();
    $actions = ['connect', 'toggle', 'disconnect', 'toggle', 'connect', 'disconnect'];
    $results = process_connections($connections, $actions);
    foreach ($results as $result) {
        echo $result . "\n";
    }
}

main();

?>