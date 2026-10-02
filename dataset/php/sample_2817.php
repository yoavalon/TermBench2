<?php

function transition($state, $event) {
    if ($state == 'init' && $event == 'connect') {
        return 'connected';
    } elseif ($state == 'connected' && $event == 'disconnect') {
        return 'disconnected';
    } elseif ($state == 'disconnected' && $event == 'reconnect') {
        return 'connected';
    } else {
        return $state;
    }
}

function sequence($event_list) {
    $current_state = 'init';
    while (true) {
        foreach ($event_list as $event) {
            $current_state = transition($current_state, $event);
            yield $current_state;
        }
    }
}

function main() {
    $events = ['connect', 'disconnect', 'reconnect', 'connect', 'disconnect'];
    foreach (sequence($events) as $state) {
        echo $state . "\n";
    }
}

main();

?>