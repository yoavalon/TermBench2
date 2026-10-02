<?php
function network_state_machine() {
    $states = array('disconnected', 'connecting', 'connected', 'disconnecting');
    $state_index = 0;
    while (true) {
        $state = $states[$state_index];
        echo $state . "\n";
        $state_index = ($state_index + 1) % count($states);
    }
}
network_state_machine();
?>