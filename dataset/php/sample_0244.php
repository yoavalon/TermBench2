<?php

class NetworkState {
    public $state;

    public function __construct() {
        $this->state = 'init';
    }

    public function transition($event) {
        if ($this->state == 'init' && $event == 'connect') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'disconnected';
        } elseif ($this->state == 'disconnected' && $event == 'reconnect') {
            $this->state = 'connected';
        }
    }
}

class EventProcessor {
    public $state_machine;
    public $events;

    public function __construct($state_machine) {
        $this->state_machine = $state_machine;
        $this->events = array();
    }

    public function add_event($event) {
        array_push($this->events, $event);
    }

    public function process_events() {
        foreach ($this->events as $event) {
            $this->state_machine->transition($event);
        }
        $this->events = array();
    }
}

function main() {
    $state_machine = new NetworkState();
    $processor = new EventProcessor($state_machine);
    $processor->add_event('connect');
    $processor->process_events();
    $processor->add_event('disconnect');
    $processor->process_events();
    $processor->add_event('reconnect');
    $processor->process_events();
    echo $state_machine->state;
}

main();

?>