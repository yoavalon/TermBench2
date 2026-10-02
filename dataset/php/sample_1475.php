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
            $this->connection = 'active';
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'idle';
            $this->connection = null;
        } elseif ($this->state == 'connected' && $event == 'data') {
            $this->state = 'processing';
        } elseif ($this->state == 'processing' && $event == 'complete') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $event == 'error') {
            $this->state = 'error';
            $this->connection = null;
        } elseif ($this->state == 'error' && $event == 'reset') {
            $this->state = 'idle';
        }
    }
}

class EventGenerator {

    public $events;
    public $index;

    function __construct() {
        $this->events = ['connect', 'disconnect', 'data', 'complete', 'error', 'reset'];
        $this->index = 0;
    }

    function generate() {
        $event = $this->events[$this->index];
        $this->index = ($this->index + 1) % count($this->events);
        return $event;
    }
}

function main() {
    $machine = new StateMachine();
    $generator = new EventGenerator();
    for ($i = 0; $i < 20; $i++) {
        $event = $generator->generate();
        $machine->transition($event);
        echo "Event: $event, State: {$machine->state}, Connection: {$machine->connection}\n";
    }
}

main();

?>