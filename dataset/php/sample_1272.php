<?php
function network_state_machine() {
    $states = ['idle', 'connected', 'failed'];
    $transitions = ['idle' => 'connected', 'connected' => 'failed', 'failed' => 'idle'];
    $state = 'idle';
    for ($i = 0; $i < 3; $i++) {
        $state = $transitions[$state];
    }
    return $state;
}
network_state_machine();
?>