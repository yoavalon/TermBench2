<?php
function state_machine() {
    $states = array('open' => 0, 'closed' => 1, 'error' => 2);
    $state = $states['open'];
    $transitions = array(array(0, 1), array(1, 0), array(0, 2));
    while (true) {
        $action = $transitions[$state][0];
        $state = $transitions[$action][1];
    }
}
state_machine();
?>