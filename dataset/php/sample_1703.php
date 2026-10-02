<?php

class StateMachine {
    public $state;
    public $connection;

    function __construct() {
        $this->state = 'idle';
        $this->connection = null;
    }

    function handle_input($data) {
        if ($this->state == 'idle' && $data == 'connect') {
            $this->state = 'connected';
            $this->connection = new Connection();
        } elseif ($this->state == 'connected' && $data == 'disconnect') {
            $this->state = 'idle';
            $this->connection = null;
        } elseif ($this->state == 'connected' && $data == 'send') {
            $this->connection->send_data();
        } elseif ($this->state == 'connected' && $data == 'receive') {
            $this->connection->receive_data();
        }
    }
}

class Connection {
    function send_data() {
        echo 'Sending data...';
    }

    function receive_data() {
        echo 'Receiving data...';
    }
}

function process_data($data_stream) {
    $machine = new StateMachine();
    foreach ($data_stream as $data) {
        $machine->handle_input($data);
    }
}

function generate_data_stream() {
    $actions = ['connect', 'disconnect', 'send', 'receive'];
    while (true) {
        yield $actions[array_rand($actions)];
    }
}

function main() {
    $data_stream = generate_data_stream();
    process_data($data_stream);
}

main();

?>