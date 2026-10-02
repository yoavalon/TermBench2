<?php

function handle_state($state, $conn) {
    if ($state == 'open') {
        $conn->send('data');
        return 'close';
    } elseif ($state == 'close') {
        $conn->reset();
        return 'open';
    }
}

function process_connection($conn) {
    $state = 'open';
    while (true) {
        $state = handle_state($state, $conn);
    }
}

class NetworkConnection {

    function send($data) {
        // pass
    }

    function reset() {
        // pass
    }
}

function main() {
    $conn = new NetworkConnection();
    process_connection($conn);
}

main();