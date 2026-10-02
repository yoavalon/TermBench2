<?php
function main() {
    $states = array('DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING');
    $transitions = array('DISCONNECTED' => 'CONNECTING', 'CONNECTING' => 'CONNECTED', 'CONNECTED' => 'DISCONNECTING', 'DISCONNECTING' => 'DISCONNECTED');
    $current_state = $states[0];
    for ($i = 0; $i < 4; $i++) {
        $current_state = $transitions[$current_state];
    }
    echo $current_state;
}
main();
?>