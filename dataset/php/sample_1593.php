<?php
function network_state_machine() {
    $states = ['init', 'open', 'data', 'close'];
    $state = $states[0];
    $transitions = ['init' => 'open', 'open' => 'data', 'data' => 'close', 'close' => 'open'];
    while (true) {
        $state = $transitions[$state];
        echo $state . "\n";
    }
}
network_state_machine();
?>