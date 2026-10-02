<?php

class ConnectionState {

    public $state;
    public $data;

    function __construct() {
        $this->state = 'DISCONNECTED';
        $this->data = [];
    }

    function connect() {
        $this->state = 'CONNECTED';
    }

    function disconnect() {
        $this->state = 'DISCONNECTED';
    }

    function send($message) {
        if ($this->state == 'CONNECTED') {
            array_push($this->data, $message);
            return true;
        }
        return false;
    }

    function receive() {
        if ($this->state == 'CONNECTED' && count($this->data) > 0) {
            return array_shift($this->data);
        }
        return null;
    }
}

class NetworkMonitor {

    public $connection;
    public $status;

    function __construct($connection) {
        $this->connection = $connection;
        $this->status = 'IDLE';
    }

    function start_monitoring() {
        $this->status = 'MONITORING';
        while (true) {
            if ($this->connection->state == 'DISCONNECTED') {
                $this->connection->connect();
                $this->status = 'CONNECTED';
            } elseif ($this->connection->state == 'CONNECTED') {
                $message = $this->connection->receive();
                if ($message) {
                    $this->process_message($message);
                }
            }
        }
    }

    function process_message($message) {
        echo "Processing message: $message\n";
    }
}

function main() {
    $conn = new ConnectionState();
    $monitor = new NetworkMonitor($conn);
    $monitor->start_monitoring();
}

main();
?>