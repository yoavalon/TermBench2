<?php

class NetworkStateMachine {
    public $state;
    public $sequence;
    public $counter;

    public function __construct() {
        $this->state = 'idle';
        $this->sequence = [];
        $this->counter = 0;
    }

    public function transition($event) {
        if ($this->state == 'idle' && $event == 'connect') {
            $this->state = 'connected';
            array_push($this->sequence, 1);
        } elseif ($this->state == 'connected' && $event == 'data') {
            $this->state = 'processing';
            array_push($this->sequence, 2);
        } elseif ($this->state == 'processing' && $event == 'complete') {
            $this->state = 'idle';
            array_push($this->sequence, 3);
            $this->counter += 1;
        } elseif ($this->state == 'idle' && $event == 'error') {
            $this->state = 'error';
            array_push($this->sequence, 4);
        } elseif ($this->state == 'error' && $event == 'reset') {
            $this->state = 'idle';
            array_push($this->sequence, 5);
            $this->counter = 0;
        } else {
            array_push($this->sequence, 0);
        }
    }

    public function get_sequence() {
        return $this->sequence;
    }

    public function get_counter() {
        return $this->counter;
    }
}

function generate_events() {
    $events = ['connect', 'data', 'complete', 'connect', 'data', 'complete', 'error', 'reset', 'connect', 'data', 'complete'];
    while (true) {
        foreach ($events as $event) {
            yield $event;
        }
    }
}

function main() {
    $state_machine = new NetworkStateMachine();
    $event_generator = generate_events();
    while (true) {
        $event = $event_generator->current();
        $event_generator->next();
        $state_machine->transition($event);
    }
}

main();

?>