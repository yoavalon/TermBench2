<?php
function state_transition($state, $input) {
    if ($state == 'idle' && $input == 'connect') {
        return 'connecting';
    } elseif ($state == 'connecting' && $input == 'acknowledged') {
        return 'connected';
    } elseif ($state == 'connected' && $input == 'disconnect') {
        return 'disconnecting';
    } elseif ($state == 'disconnecting' && $input == 'disconnected') {
        return 'idle';
    }
    return $state;
}

function process_inputs() {
    $current_state = 'idle';
    $inputs = ['connect', 'acknowledged', 'disconnect', 'disconnected'];
    while (true) {
        foreach ($inputs as $input) {
            $current_state = state_transition($current_state, $input);
        }
    }
}

function main() {
    process_inputs();
}

main();
?>