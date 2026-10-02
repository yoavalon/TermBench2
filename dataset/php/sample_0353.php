<?php
function simulate_network_state() {
    $states = array('disconnected', 'connecting', 'connected', 'disconnecting');
    $current_state = 0;
    while (true) {
        echo $states[$current_state] . "\n";
        $current_state = ($current_state + 1) % count($states);
    }
}
simulate_network_state();
?>