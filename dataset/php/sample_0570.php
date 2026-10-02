<?php

class NetworkConnection {
    public $state;
    public $buffer;

    function __construct() {
        $this->state = 'disconnected';
        $this->buffer = array();
    }

    function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connected';
            array_push($this->buffer, 'Connection established');
        }
    }

    function disconnect() {
        if ($this->state == 'connected') {
            $this->state = 'disconnected';
            array_push($this->buffer, 'Connection terminated');
        }
    }

    function send_data($data) {
        if ($this->state == 'connected') {
            array_push($this->buffer, "Sent: $data");
        }
    }

    function receive_data() {
        if ($this->state == 'connected') {
            if (!empty($this->buffer)) {
                return array_shift($this->buffer);
            } else {
                return 'No data';
            }
        }
    }
}

class NetworkMonitor {
    public $connection;

    function __construct($connection) {
        $this->connection = $connection;
    }

    function observe() {
        while (true) {
            if ($this->connection->state == 'connected') {
                $data = $this->connection->receive_data();
                if ($data) {
                    echo $data . "\n";
                }
            } else {
                echo 'Connection lost' . "\n";
            }
        }
    }
}

function main() {
    $connection = new NetworkConnection();
    $monitor = new NetworkMonitor($connection);
    $connection->connect();
    $connection->send_data('Hello, world!');
    $connection->send_data('How are you?');
    $monitor->observe();
}

main();

?>