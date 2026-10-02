<?php

class NetworkConnection {
    public $state;

    function __construct($state = 'disconnected') {
        $this->state = $state;
    }

    function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connected';
        }
        return $this->state;
    }

    function disconnect() {
        if ($this->state == 'connected') {
            $this->state = 'disconnected';
        }
        return $this->state;
    }

    function is_connected() {
        return $this->state == 'connected';
    }
}

class StateMachine {
    public $connection;

    function __construct() {
        $this->connection = new NetworkConnection();
    }

    function process($command) {
        if ($command == 'connect') {
            return $this->connection->connect();
        } elseif ($command == 'disconnect') {
            return $this->connection->disconnect();
        } elseif ($command == 'status') {
            return $this->connection->is_connected();
        }
    }
}

function simulate_network_activity($state_machine) {
    while (true) {
        if ($state_machine->process('connect')) {
            echo 'Connection established.';
            while ($state_machine->process('status')) {
                echo 'Connected.';
            }
        }
        echo 'Connection lost.';
        $state_machine->process('disconnect');
    }
}

function main() {
    $state_machine = new StateMachine();
    simulate_network_activity($state_machine);
}

main();

?>