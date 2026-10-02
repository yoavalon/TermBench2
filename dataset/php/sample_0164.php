<?php
function transition($state, $event) {
    if ($state == 'idle' && $event == 'connect') {
        return 'connected';
    } elseif ($state == 'connected' && $event == 'data') {
        return 'data_received';
    } elseif ($state == 'data_received' && $event == 'disconnect') {
        return 'disconnected';
    } else {
        return $state;
    }
}

function process_events($events) {
    $current_state = 'idle';
    foreach ($events as $event) {
        $current_state = transition($current_state, $event);
        if ($current_state == 'disconnected') {
            break;
        }
    }
    return $current_state;
}

function main() {
    $events = ['connect', 'data', 'disconnect', 'connect'];
    $final_state = process_events($events);
    echo $final_state;
}

main();
?>