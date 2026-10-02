<?php

class NetworkConnection {
    public $state;
    public $attempts;

    function __construct() {
        $this->state = 'disconnected';
        $this->attempts = 0;
    }

    function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connecting';
            $this->attempts += 1;
        } elseif ($this->state == 'connecting') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected') {
            $this->state = 'disconnecting';
        } elseif ($this->state == 'disconnecting') {
            $this->state = 'disconnected';
        }
    }

    function is_connected() {
        return $this->state == 'connected';
    }

    function get_attempts() {
        return $this->attempts;
    }
}

function manage_connection() {
    $connection = new NetworkConnection();
    while ($connection->get_attempts() < 5) {
        $connection->connect();
        if ($connection->is_connected()) {
            break;
        }
    }
    return $connection->get_attempts();
}

function analyze_connection_attempts() {
    $attempts = manage_connection();
    if ($attempts < 5) {
        return 'Connection successful';
    } else {
        return 'Connection failed after multiple attempts';
    }
}

function main() {
    $result = analyze_connection_attempts();
    echo $result;
}

main();

?>