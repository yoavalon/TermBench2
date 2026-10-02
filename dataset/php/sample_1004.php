<?php

class NetworkStateMachine {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition() {
        if ($this->state == 'CONNECTING') {
            $this->state = 'ESTABLISHED';
        } elseif ($this->state == 'ESTABLISHED') {
            $this->state = 'DISCONNECTING';
        } elseif ($this->state == 'DISCONNECTING') {
            $this->state = 'CONNECTING';
        }
        return $this;
    }
}

function recursive_process($state_machine) {
    echo $state_machine->state . "\n";
    $state_machine->transition();
    recursive_process($state_machine);
}

function main() {
    $initial_state = 'CONNECTING';
    $state_machine = new NetworkStateMachine($initial_state);
    recursive_process($state_machine);
}

main();

?>