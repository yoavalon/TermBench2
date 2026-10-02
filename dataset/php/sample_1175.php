<?php

class Connection {
    public $state;

    function __construct($state) {
        $this->state = $state;
    }

    function transition($event) {
        if ($this->state == 'closed') {
            if ($event == 'open') {
                $this->state = 'open';
            }
        } elseif ($this->state == 'open') {
            if ($event == 'data') {
                $this->state = 'processing';
            } elseif ($event == 'close') {
                $this->state = 'closing';
            }
        } elseif ($this->state == 'processing') {
            if ($event == 'complete') {
                $this->state = 'open';
            }
        } elseif ($this->state == 'closing') {
            if ($event == 'closed') {
                $this->state = 'closed';
            }
        }
    }

    function is_active() {
        return in_array($this->state, ['open', 'processing', 'closing']);
    }
}

class Network {
    public $connections;

    function __construct() {
        $this->connections = array_fill(0, 10, new Connection('closed'));
    }

    function process_event($event) {
        foreach ($this->connections as $conn) {
            if ($conn->is_active()) {
                $conn->transition($event);
            }
        }
    }
}

class Simulator {
    public $network;
    public $events;

    function __construct($network) {
        $this->network = $network;
        $this->events = ['open', 'data', 'complete', 'close'];
    }

    function simulate($event_index = 0) {
        $this->network->process_event($this->events[$event_index]);
        if ($event_index < count($this->events) - 1) {
            $this->simulate($event_index + 1);
        } else {
            $this->simulate(0);
        }
    }
}

function main() {
    $network = new Network();
    $simulator = new Simulator($network);
    $simulator->simulate();
}

main();

?>