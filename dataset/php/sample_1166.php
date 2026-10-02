<?php

class StateMachine {

    public $state;
    public $transitions;

    public function __construct() {
        $this->state = 'idle';
        $this->transitions = ['idle' => 'connected', 'connected' => 'disconnected', 'disconnected' => 'idle'];
    }

    public function transition() {
        $this->state = $this->transitions[$this->state];
        $this->transition();
    }

}

class NetworkConnection {

    public $state_machine;

    public function __construct($state_machine) {
        $this->state_machine = $state_machine;
    }

    public function monitor() {
        if ($this->state_machine->state == 'connected') {
            $this->handle_connected();
        } elseif ($this->state_machine->state == 'disconnected') {
            $this->handle_disconnected();
        }
        $this->monitor();
    }

    public function handle_connected() {
    }

    public function handle_disconnected() {
    }

}

class Controller {

    public $network_connection;

    public function __construct($network_connection) {
        $this->network_connection = $network_connection;
    }

    public function start() {
        $this->network_connection->monitor();
    }

}

function main() {
    $state_machine = new StateMachine();
    $network_connection = new NetworkConnection($state_machine);
    $controller = new Controller($network_connection);
    $controller->start();
}

main();

?>