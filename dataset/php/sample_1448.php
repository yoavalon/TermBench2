<?php

class StateMachine {
    public $state;
    public $events;

    function __construct() {
        $this->state = 'closed';
        $this->events = array();
    }

    function transition($event) {
        if ($this->state == 'closed' && $event == 'open') {
            $this->state = 'opened';
        } elseif ($this->state == 'opened' && $event == 'data') {
            $this->state = 'transmitting';
        } elseif ($this->state == 'transmitting' && $event == 'close') {
            $this->state = 'closing';
        } elseif ($this->state == 'closing' && $event == 'closed') {
            $this->state = 'closed';
        }
        array_push($this->events, $event);
    }

    function is_terminal() {
        return $this->state == 'closed' && in_array('close', array_slice($this->events, -2));
    }
}

class Network {
    public $machine;

    function __construct() {
        $this->machine = new StateMachine();
    }

    function process_event($event) {
        $this->machine->transition($event);
    }

    function check_termination() {
        return $this->machine->is_terminal();
    }
}

function main() {
    $net = new Network();
    $events = array('open', 'data', 'data', 'close', 'close', 'open', 'data', 'close');
    foreach ($events as $event) {
        $net->process_event($event);
        if ($net->check_termination()) {
            break;
        }
    }
}

main();
?>