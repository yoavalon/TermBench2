<?php

class StateMachine {
    public $state;

    function __construct($state) {
        $this->state = $state;
    }

    function transition($event) {
        if ($this->state == 'idle') {
            if ($event == 'connect') {
                $this->state = 'connected';
            } elseif ($event == 'disconnect') {
                $this->state = 'disconnected';
            }
        } elseif ($this->state == 'connected') {
            if ($event == 'data') {
                $this->state = 'data_received';
            } elseif ($event == 'disconnect') {
                $this->state = 'disconnected';
            }
        } elseif ($this->state == 'data_received') {
            if ($event == 'ack') {
                $this->state = 'idle';
            } elseif ($event == 'disconnect') {
                $this->state = 'disconnected';
            }
        } elseif ($this->state == 'disconnected') {
            if ($event == 'connect') {
                $this->state = 'connected';
            }
        }
    }

    function get_state() {
        return $this->state;
    }
}

function simulate_network_events($sm, $events) {
    foreach ($events as $event) {
        $sm->transition($event);
    }
}

function check_termination($sm, $target_state, $max_steps) {
    $steps = 0;
    while ($sm->get_state() != $target_state && $steps < $max_steps) {
        $sm->transition('data');
        $steps += 1;
    }
    return $sm->get_state() == $target_state;
}

function main() {
    $sm = new StateMachine('idle');
    $events = ['connect', 'data', 'ack', 'disconnect'];
    simulate_network_events($sm, $events);
    $terminated = check_termination($sm, 'idle', 10);
    echo $terminated;
}

main();