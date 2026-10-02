<?php

class StateMachine {
    public $state;

    public function __construct() {
        $this->state = 'idle';
    }

    public function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'idle';
        } elseif ($this->state == 'idle' && $event == 'error') {
            $this->state = 'error';
        } elseif ($this->state == 'error' && $event == 'recover') {
            $this->state = 'idle';
        }
        return $this->state;
    }
}

function process_events($events) {
    $machine = new StateMachine();
    foreach ($events as $event) {
        $machine->transition($event);
    }
    return $machine->state;
}

function main() {
    $events = array('connect', 'disconnect', 'connect', 'error', 'recover');
    $final_state = process_events($events);
    echo $final_state;
}

main();
?>