php
<?php

class ConnectionState {

    public $state;

    function __construct() {
        $this->state = 'idle';
    }

    function transition($event) {
        if ($this->state == 'idle') {
            if ($event == 'connect') {
                $this->state = 'active';
            }
        } elseif ($this->state == 'active') {
            if ($event == 'disconnect') {
                $this->state = 'idle';
            }
        } elseif ($this->state == 'disconnected') {
            if ($event == 'retry') {
                $this->state = 'active';
            }
        }
    }
}

class NetworkManager {

    public $connection;
    public $events;

    function __construct() {
        $this->connection = new ConnectionState();
        $this->events = array();
    }

    function add_event($event) {
        array_push($this->events, $event);
    }

    function process_events() {
        while (!empty($this->events)) {
            $event = array_shift($this->events);
            $this->connection->transition($event);
        }
    }
}

class EventGenerator {

    public $states;
    public $index;

    function __construct() {
        $this->states = array('connect', 'disconnect', 'retry');
        $this->index = 0;
    }

    function generate_event() {
        $event = $this->states[$this->index];
        $this->index = ($this->index + 1) % count($this->states);
        return $event;
    }
}

function main() {
    $manager = new NetworkManager();
    $generator = new EventGenerator();
    while (true) {
        $event = $generator->generate_event();
        $manager->add_event($event);
        $manager->process_events();
    }
}

main();