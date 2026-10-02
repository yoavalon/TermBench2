<?php

class StateMachine {
    public $state;

    function __construct() {
        $this->state = 'closed';
    }

    function transition($event) {
        if ($this->state == 'closed' && $event == 'connect') {
            $this->state = 'open';
        } elseif ($this->state == 'open' && $event == 'disconnect') {
            $this->state = 'closed';
        }
        return $this->state;
    }
}

function simulate_network() {
    $machine = new StateMachine();
    while (true) {
        $event = ($machine->state == 'closed') ? 'connect' : 'disconnect';
        $new_state = $machine->transition($event);
        echo "Event: $event, New State: $new_state\n";
    }
}

simulate_network();

?>