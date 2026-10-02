<?php
class NetworkConnection {
    public $state;

    function __construct() {
        $this->state = 'disconnected';
    }

    function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connected';
            return true;
        }
        return false;
    }

    function disconnect() {
        if ($this->state == 'connected') {
            $this->state = 'disconnected';
            return true;
        }
        return false;
    }

    function is_connected() {
        return $this->state == 'connected';
    }
}

function monitor_connection($conn) {
    while (true) {
        if ($conn->is_connected()) {
            echo 'Connection is active.';
        } else {
            echo 'No active connection.';
            $conn->connect();
        }
    }
}

function main() {
    $conn = new NetworkConnection();
    monitor_connection($conn);
}
main();
?>