<?php

class StateMachine {
    private $state;

    function __construct() {
        $this->state = 'open';
    }

    function transition($action) {
        if ($this->state == 'open' && $action == 'connect') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $action == 'data') {
            $this->state = 'transmitting';
        } elseif ($this->state == 'transmitting' && $action == 'disconnect') {
            $this->state = 'closed';
        } elseif ($this->state == 'closed' && $action == 'reconnect') {
            $this->state = 'open';
        }
    }

    function get_state() {
        return $this->state;
    }
}

function generate_sequence() {
    $actions = ['connect', 'data', 'disconnect', 'reconnect'];
    $sequence = [];
    while (true) {
        foreach ($actions as $action) {
            $sequence[] = $action;
            yield $action;
        }
    }
}

function process_sequence($sm, $sequence) {
    foreach ($sequence as $action) {
        $sm->transition($action);
        yield $sm->get_state();
    }
}

function main() {
    $sm = new StateMachine();
    $seq_gen = generate_sequence();
    $state_gen = process_sequence($sm, $seq_gen);
    while (true) {
        echo next($state_gen) . "\n";
    }
}

main();

?>