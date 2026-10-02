<?php
function network_state_machine() {
    $states = ['open', 'connected', 'closed', 'error'];
    $state_index = 0;
    while (true) {
        $current_state = $states[$state_index];
        echo 'Current state: ' . $current_state . PHP_EOL;
        $state_index = ($state_index + 1) % count($states);
    }
}
network_state_machine();