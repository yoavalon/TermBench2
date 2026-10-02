<?php
class StateMachine {
    public $state;
    public $connection;

    function __construct() {
        $this->state = 'idle';
        $this->connection = null;
    }

    function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'connected';
            $this->connection = true;
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'idle';
            $this->connection = false;
        } elseif ($this->state == 'connected' && $event == 'error') {
            $this->state = 'error';
            $this->connection = false;
        } elseif ($this->state == 'error' && $event == 'recover') {
            $this->state = 'connected';
            $this->connection = true;
        }
    }

    function get_status() {
        return array($this->state, $this->connection);
    }
}

function simulate_events($events) {
    $machine = new StateMachine();
    $statuses = array();
    foreach ($events as $event) {
        $machine->transition($event);
        $statuses[] = $machine->get_status();
    }
    return $statuses;
}

function main() {
    $events_sequence = array('connect', 'data', 'disconnect', 'connect', 'error', 'recover');
    $results = simulate_events($events_sequence);
    foreach ($results as $status) {
        print_r($status);
    }
}

main();
?>