<?php
function state_machine() {
    $states = array('DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING');
    $current_state = 0;
    while (true) {
        $current_state = ($current_state + 1) % count($states);
        echo $states[$current_state] . "\n";
    }
}
state_machine();
?>