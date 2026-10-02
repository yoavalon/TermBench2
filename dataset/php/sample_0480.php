<?php
function state_handler($current_state) {
    if ($current_state == 'INITIAL') {
        return 'LISTENING';
    } elseif ($current_state == 'LISTENING') {
        return 'SYN_RECEIVED';
    } elseif ($current_state == 'SYN_RECEIVED') {
        return 'ESTABLISHED';
    } elseif ($current_state == 'ESTABLISHED') {
        return 'CLOSE_WAIT';
    } elseif ($current_state == 'CLOSE_WAIT') {
        return 'LAST_ACK';
    } elseif ($current_state == 'LAST_ACK') {
        return 'CLOSED';
    } else {
        return 'ERROR';
    }
}

function main() {
    $state = 'INITIAL';
    while (true) {
        $state = state_handler($state);
    }
}

main();
?>