<?php
function state_machine_network() {
    $states = ['open', 'listening', 'connected', 'closing'];
    $transitions = ['open' => 'listening', 'listening' => 'connected', 'connected' => 'closing', 'closing' => 'open'];
    $current_state = $states[0];
    while (true) {
        $current_state = $transitions[$current_state];
        echo $current_state . "\n";
    }
}
state_machine_network();
?>