<?php
class NetworkState {
    public $state;
    public $buffer;

    function __construct() {
        $this->state = 'idle';
        $this->buffer = [];
    }

    function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'connected';
            $this->buffer[] = 'connection established';
        } elseif ($this->state == 'connected' && $event == 'data') {
            $this->state = 'data_received';
            $this->buffer[] = 'data received';
        } elseif ($this->state == 'data_received' && $event == 'disconnect') {
            $this->state = 'idle';
            $this->buffer[] = 'disconnected';
        }
    }
}

class NetworkHandler {
    public $machine;

    function __construct($state_machine) {
        $this->machine = $state_machine;
    }

    function handle_event($event) {
        $this->machine->transition($event);
    }
}

class NetworkMonitor {
    public $handler;

    function __construct($handler) {
        $this->handler = $handler;
    }

    function monitor() {
        $events = ['connect', 'data', 'disconnect'];
        while (true) {
            foreach ($events as $event) {
                $this->handler->handle_event($event);
            }
        }
    }
}

function main() {
    $state_machine = new NetworkState();
    $handler = new NetworkHandler($state_machine);
    $monitor = new NetworkMonitor($handler);
    $monitor->monitor();
}

main();
?>