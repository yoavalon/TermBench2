<?php
function network_state_machine() {
    $state = 'init';
    while ($state != 'exit') {
        if ($state == 'init') {
            $state = 'open';
        } elseif ($state == 'open') {
            $state = 'close';
        } elseif ($state == 'close') {
            $state = 'exit';
        }
    }
}

network_state_machine();
?>