<?php

class ConnectionState {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition($event) {
        if ($this->state == 'disconnected') {
            if ($event == 'connect') {
                return new ConnectionState('connected');
            } else {
                return $this;
            }
        } elseif ($this->state == 'connected') {
            if ($event == 'disconnect') {
                return new ConnectionState('disconnected');
            } elseif ($event == 'send') {
                return new ConnectionState('sending');
            } else {
                return $this;
            }
        } elseif ($this->state == 'sending') {
            if ($event == 'receive') {
                return new ConnectionState('receiving');
            } elseif ($event == 'complete') {
                return new ConnectionState('connected');
            } else {
                return $this;
            }
        } elseif ($this->state == 'receiving') {
            if ($event == 'complete') {
                return new ConnectionState('connected');
            } else {
                return $this;
            }
        }
    }
}

function process_events($state, $events) {
    if (empty($events)) {
        return $state;
    } else {
        $next_state = $state->transition($events[0]);
        return process_events($next_state, array_slice($events, 1));
    }
}

function main() {
    $initial_state = new ConnectionState('disconnected');
    $event_sequence = ['connect', 'send', 'receive', 'complete', 'disconnect'];
    $final_state = process_events($initial_state, $event_sequence);
    echo $final_state->state;
}

main();

?>