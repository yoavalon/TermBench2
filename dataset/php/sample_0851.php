<?php

class Connection {
    public $status;

    function __construct($status) {
        $this->status = $status;
    }

    function change_status($new_status) {
        $this->status = $new_status;
    }
}

class StateMachine {
    public $current_state;

    function __construct($initial_state) {
        $this->current_state = $initial_state;
    }

    function transition($event) {
        if ($this->current_state == 'disconnected' && $event == 'connect') {
            $this->current_state = 'connected';
        } elseif ($this->current_state == 'connected' && $event == 'disconnect') {
            $this->current_state = 'disconnected';
        }
    }
}

function process_event($state_machine, $event, $connection) {
    if ($event == 'connect') {
        $connection->change_status('active');
    } elseif ($event == 'disconnect') {
        $connection->change_status('inactive');
    }
    $state_machine->transition($event);
}

function simulate_network_activity($state_machine, $connection, $events) {
    if (empty($events)) {
        return;
    }
    $event = $events[0];
    process_event($state_machine, $event, $connection);
    simulate_network_activity($state_machine, $connection, array_slice($events, 1));
}

function main() {
    $connection = new Connection('inactive');
    $state_machine = new StateMachine('disconnected');
    $events = ['connect', 'disconnect', 'connect', 'disconnect', 'connect'];
    simulate_network_activity($state_machine, $connection, $events);
}

main();

?>