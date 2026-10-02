<?php
function state_machine() {
    $states = array('CLOSED', 'LISTEN', 'SYN_SENT', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'CLOSING', 'TIME_WAIT', 'LAST_ACK');
    $current_state = $states[0];
    while (true) {
        $event = $states[($states[array_search($current_state, $states)] + 1) % count($states)];
        $current_state = $event;
        echo $current_state . "\n";
    }
}
state_machine();
?>