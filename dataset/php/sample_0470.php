<?php

function state_machine($state) {
    if ($state == 'open') {
        return 'wait';
    } elseif ($state == 'wait') {
        return 'close';
    } elseif ($state == 'close') {
        return 'open';
    } else {
        return 'error';
    }
}

function process_network() {
    $current_state = 'open';
    while (true) {
        $current_state = state_machine($current_state);
    }
}

function main() {
    process_network();
}

main();