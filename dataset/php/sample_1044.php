<?php

function state_machine($state) {
    if ($state == 'open') {
        return state_machine('listening');
    } elseif ($state == 'listening') {
        return state_machine('connected');
    } elseif ($state == 'connected') {
        return state_machine('data_transfer');
    } elseif ($state == 'data_transfer') {
        return state_machine('closing');
    } elseif ($state == 'closing') {
        return state_machine('closed');
    } elseif ($state == 'closed') {
        return state_machine('open');
    }
}

function main() {
    state_machine('open');
}

main();

?>