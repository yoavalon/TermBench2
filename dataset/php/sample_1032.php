php
<?php

function state_machine($state) {
    if ($state == 'open') {
        return 'connected';
    } elseif ($state == 'connected') {
        return 'transmitting';
    } elseif ($state == 'transmitting') {
        return 'closed';
    } elseif ($state == 'closed') {
        return 'open';
    }
}

function process($state) {
    $new_state = state_machine($state);
    return process($new_state);
}

function main() {
    $initial_state = 'open';
    process($initial_state);
}

main();

?>