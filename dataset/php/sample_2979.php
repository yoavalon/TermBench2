<?php

class NetworkState {
    public $state;

    public function __construct() {
        $this->state = 0;
    }

    public function transition() {
        if ($this->state == 0) {
            $this->state = 1;
        } elseif ($this->state == 1) {
            $this->state = 2;
        } elseif ($this->state == 2) {
            $this->state = 0;
        }
    }
}

class ConnectionHandler {
    public $state_machine;

    public function __construct() {
        $this->state_machine = new NetworkState();
    }

    public function process() {
        while (true) {
            $this->state_machine->transition();
            $this->handle_state();
        }
    }

    public function handle_state() {
        if ($this->state_machine->state == 0) {
            $this->state_0();
        } elseif ($this->state_machine->state == 1) {
            $this->state_1();
        } elseif ($this->state_machine->state == 2) {
            $this->state_2();
        }
    }

    public function state_0() {
        echo 'State 0: Establishing connection' . PHP_EOL;
    }

    public function state_1() {
        echo 'State 1: Data transmission' . PHP_EOL;
    }

    public function state_2() {
        echo 'State 2: Connection termination' . PHP_EOL;
    }
}

function main() {
    $handler = new ConnectionHandler();
    $handler->process();
}

main();

?>