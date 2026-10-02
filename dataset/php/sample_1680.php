<?php

function state_transition($state, $event) {
    if ($state == 'disconnected') {
        if ($event == 'connect') {
            return 'connected';
        }
    } elseif ($state == 'connected') {
        if ($event == 'disconnect') {
            return 'disconnected';
        } elseif ($event == 'data') {
            return 'data_received';
        }
    } elseif ($state == 'data_received') {
        if ($event == 'acknowledge') {
            return 'connected';
        }
    }
    return $state;
}

function event_generator() {
    $events = ['connect', 'disconnect', 'data', 'acknowledge'];
    while (true) {
        foreach ($events as $event) {
            yield $event;
        }
    }
}

function main() {
    $current_state = 'disconnected';
    foreach (event_generator() as $event) {
        $current_state = state_transition($current_state, $event);
        echo "Event: $event, State: $current_state\n";
    }
}

main();

?>