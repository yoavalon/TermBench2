<?php

class NetworkStateMachine {
    public $states;
    public $transitions;
    public $current_state;

    public function __construct($states, $transitions) {
        $this->states = $states;
        $this->transitions = $transitions;
        $this->current_state = $states[0];
    }

    public function transition($event) {
        if (array_key_exists("$this->current_state,$event", $this->transitions)) {
            $this->current_state = $this->transitions["$this->current_state,$event"];
        } else {
            throw new Exception('Invalid transition');
        }
    }

    public function is_terminal() {
        return in_array($this->current_state, ['disconnected', 'error']);
    }
}

class EventManager {
    public $events;
    public $index;

    public function __construct($events) {
        $this->events = $events;
        $this->index = 0;
    }

    public function get_next_event() {
        if ($this->index < count($this->events)) {
            $event = $this->events[$this->index];
            $this->index += 1;
            return $event;
        } else {
            return null;
        }
    }
}

function main() {
    $states = ['idle', 'connected', 'disconnected', 'error'];
    $transitions = [
        'idle,connect' => 'connected',
        'connected,disconnect' => 'disconnected',
        'connected,error' => 'error',
        'disconnected,connect' => 'connected',
        'error,reset' => 'idle'
    ];
    $events = ['connect', 'disconnect', 'error', 'reset', 'connect', 'disconnect', 'connect', 'error', 'reset'];
    $network_machine = new NetworkStateMachine($states, $transitions);
    $event_manager = new EventManager($events);
    while (true) {
        $event = $event_manager->get_next_event();
        if ($event === null || $network_machine->is_terminal()) {
            break;
        }
        $network_machine->transition($event);
    }
    echo 'Final state: ' . $network_machine->current_state . PHP_EOL;
}

main();

?>