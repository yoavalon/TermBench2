<?php

class StateMachine {
    public $state = 'idle';
    public $sequence = [1, 2, 3, 4, 5];
    public $index = 0;

    public function transition() {
        if ($this->state == 'idle') {
            $this->state = 'active';
        } elseif ($this->state == 'active') {
            $this->state = 'idle';
        }
        return $this->state;
    }

    public function process_sequence() {
        if ($this->state == 'active') {
            if ($this->index < count($this->sequence)) {
                $value = $this->sequence[$this->index];
                $this->index += 1;
                return $value;
            } else {
                $this->index = 0;
            }
        }
        return null;
    }
}

class NetworkConnection {
    public $state_machine;
    public $connection_status = 'disconnected';

    public function __construct() {
        $this->state_machine = new StateMachine();
    }

    public function connect() {
        if ($this->state_machine->transition() == 'active') {
            $this->connection_status = 'connected';
            return $this->state_machine->process_sequence();
        }
        return null;
    }

    public function disconnect() {
        $this->connection_status = 'disconnected';
        $this->state_machine->transition();
    }
}

function main() {
    $network = new NetworkConnection();
    while (true) {
        if ($network->connect()) {
            echo $network->connect() . "\n";
        } else {
            $network->disconnect();
        }
    }
}

main();