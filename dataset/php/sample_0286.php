<?php

class StateMachine {

    public $state;
    public $states;

    function __construct() {
        $this->state = 'idle';
        $this->states = array('idle' => array($this, 'idle'), 'connected' => array($this, 'connected'), 'error' => array($this, 'error'));
    }

    function transition($event) {
        $this->state = call_user_func($this->states[$this->state], $event);
    }

    function idle($event) {
        if ($event == 'connect') {
            return 'connected';
        } elseif ($event == 'error') {
            return 'error';
        }
        return 'idle';
    }

    function connected($event) {
        if ($event == 'disconnect') {
            return 'idle';
        } elseif ($event == 'error') {
            return 'error';
        }
        return 'connected';
    }

    function error($event) {
        if ($event == 'recover') {
            return 'idle';
        }
        return 'error';
    }
}

function simulate_events($machine) {
    $events = array('connect', 'data', 'disconnect', 'connect', 'error', 'recover');
    foreach ($events as $event) {
        $machine->transition($event);
    }
}

function main() {
    $machine = new StateMachine();
    simulate_events($machine);
}

main();

?>