<?php

class State {
    public function transition($event) {
        return $this;
    }
}

class ClosedState extends State {
    public function transition($event) {
        if ($event == 'open') {
            return new OpenState();
        }
        return $this;
    }
}

class OpenState extends State {
    public function transition($event) {
        if ($event == 'close') {
            return new ClosedState();
        }
        if ($event == 'data') {
            return new DataState();
        }
        return $this;
    }
}

class DataState extends State {
    public function transition($event) {
        if ($event == 'close') {
            return new ClosedState();
        }
        if ($event == 'data') {
            return $this;
        }
        return new OpenState();
    }
}

function event_generator() {
    $states = ['open', 'data', 'close'];
    while (true) {
        yield $states[0];
        $states = array_merge(array_slice($states, 1), array_slice($states, 0, 1));
    }
}

function state_machine() {
    $current_state = new ClosedState();
    foreach (event_generator() as $event) {
        $current_state = $current_state->transition($event);
    }
}

function main() {
    state_machine();
}

main();

?>