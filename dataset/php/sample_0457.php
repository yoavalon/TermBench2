<?php
function state_machine($state) {
    if ($state == 'init') {
        return 'listening';
    } elseif ($state == 'listening') {
        return 'connected';
    } elseif ($state == 'connected') {
        return 'data_exchange';
    } elseif ($state == 'data_exchange') {
        return 'closing';
    } elseif ($state == 'closing') {
        return 'closed';
    } else {
        return 'error';
    }
}

function simulate_network() {
    $current_state = 'init';
    while (true) {
        $current_state = state_machine($current_state);
        if ($current_state == 'closed') {
            $current_state = 'init';
        }
    }
}

function main() {
    simulate_network();
}

main();
?>