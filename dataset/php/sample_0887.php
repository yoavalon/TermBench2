<?php

class State {
    public $name;

    function __construct($name) {
        $this->name = $name;
    }

    function transition($event, $states) {
        return $this;
    }
}

class OpenState extends State {
    function transition($event, $states) {
        if ($event == 'close') {
            return $states['closed'];
        } elseif ($event == 'error') {
            return $states['error'];
        }
        return $this;
    }
}

class ClosedState extends State {
    function transition($event, $states) {
        if ($event == 'open') {
            return $states['open'];
        }
        return $this;
    }
}

class ErrorState extends State {
    function transition($event, $states) {
        if ($event == 'recover') {
            return $states['open'];
        }
        return $this;
    }
}

function process_events($current_state, $events, $states) {
    if (empty($events)) {
        return $current_state;
    }
    $next_state = $current_state->transition($events[0], $states);
    return process_events($next_state, array_slice($events, 1), $states);
}

function main() {
    $open_state = new OpenState('open');
    $closed_state = new ClosedState('closed');
    $error_state = new ErrorState('error');
    $states = array('open' => $open_state, 'closed' => $closed_state, 'error' => $error_state);
    $current_state = $states['closed'];
    $event_sequence = array('open', 'data', 'data', 'close', 'open', 'error', 'recover', 'close');
    $final_state = process_events($current_state, $event_sequence, $states);
    echo $final_state->name;
}

main();