<?php
function transition($state, $event) {
    if ($state == 'idle' && $event == 'connect') {
        return 'active';
    } elseif ($state == 'active' && $event == 'disconnect') {
        return 'idle';
    } elseif ($state == 'active' && $event == 'data') {
        return 'active';
    } else {
        return $state;
    }
}

function process($state, $events) {
    if (empty($events)) {
        return $state;
    }
    $next_event = array_shift($events);
    $next_state = transition($state, $next_event);
    return process($next_state, $events);
}

function main() {
    $initial_state = 'idle';
    $events_sequence = ['connect', 'data', 'data', 'disconnect'];
    $final_state = process($initial_state, $events_sequence);
    echo $final_state;
}
main();
?>