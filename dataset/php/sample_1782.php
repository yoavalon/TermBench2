<?php

class NetworkState {
    public $state;
    public $connection_attempts;

    public function __construct() {
        $this->state = 'disconnected';
        $this->connection_attempts = 0;
    }

    public function transition($event) {
        if ($this->state == 'disconnected' && $event == 'connect') {
            $this->state = 'connecting';
        } elseif ($this->state == 'connecting') {
            if ($event == 'success') {
                $this->state = 'connected';
                $this->connection_attempts = 0;
            } elseif ($event == 'failure') {
                $this->connection_attempts += 1;
                if ($this->connection_attempts < 5) {
                    $this->state = 'connecting';
                } else {
                    $this->state = 'disconnected';
                }
            }
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'disconnected';
        }
    }
}

class EventGenerator {
    public function generate() {
        if (rand(0, 1) == 1) {
            return 'connect';
        } else {
            return 'disconnect';
        }
    }
}

class ConnectionHandler {
    public $network;
    public $generator;

    public function __construct() {
        $this->network = new NetworkState();
        $this->generator = new EventGenerator();
    }

    public function run() {
        while (true) {
            $event = $this->generator->generate();
            $this->network->transition($event);
            if ($this->network->state == 'connected') {
                $this->handle_connected();
            } elseif ($this->network->state == 'disconnected') {
                $this->handle_disconnected();
            }
        }
    }

    public function handle_connected() {
        echo 'Connected' . PHP_EOL;
    }

    public function handle_disconnected() {
        echo 'Disconnected' . PHP_EOL;
    }
}

function main() {
    $handler = new ConnectionHandler();
    $handler->run();
}

main();

?>