<?php

function state_transition($state, $event) {
    if ($state == 'closed' && $event == 'open') {
        return 'open';
    } elseif ($state == 'open' && $event == 'close') {
        return 'closed';
    } elseif ($state == 'open' && $event == 'data') {
        return 'data';
    } elseif ($state == 'data' && $event == 'close') {
        return 'closed';
    }
    return $state;
}

function network_sequence() {
    $state = 'closed';
    while (true) {
        $event = $state == 'closed' ? 'open' : 'data';
        $state = state_transition($state, $event);
        $event = $state == 'data' ? 'close' : 'open';
        $state = state_transition($state, $event);
    }
}

network_sequence();

?>