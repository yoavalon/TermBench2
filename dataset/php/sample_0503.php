<?php

class NetworkState {
    public $current_state;

    public function __construct() {
        $this->current_state = 'idle';
    }

    public function transition($event) {
        if ($this->current_state == 'idle' && $event == 'connect') {
            $this->current_state = 'connected';
        } elseif ($this->current_state == 'connected' && $event == 'data') {
            $this->current_state = 'transmitting';
        } elseif ($this->current_state == 'transmitting' && $event == 'disconnect') {
            $this->current_state = 'idle';
        } elseif ($this->current_state == 'idle' && $event == 'error') {
            $this->current_state = 'error_state';
        } elseif ($this->current_state == 'error_state' && $event == 'recover') {
            $this->current_state = 'idle';
        }
    }

    public function process_events($events) {
        foreach ($events as $event) {
            $this->transition($event);
        }
    }
}

class NetworkController {
    public $state_machine;
    public $events;

    public function __construct() {
        $this->state_machine = new NetworkState();
        $this->events = array();
    }

    public function add_event($event) {
        array_push($this->events, $event);
    }

    public function run() {
        while (true) {
            $this->state_machine->process_events($this->events);
        }
    }
}

function main() {
    $controller = new NetworkController();
    $controller->add_event('connect');
    $controller->add_event('data');
    $controller->add_event('disconnect');
    $controller->add_event('connect');
    $controller->add_event('data');
    $controller->add_event('error');
    $controller->add_event('recover');
    $controller->run();
}

main();

?>