php
<?php

function state_machine() {
    $state = 'INIT';
    while (true) {
        if ($state == 'INIT') {
            $transition = 'CONNECT';
            $state = 'CONNECTING';
        } elseif ($state == 'CONNECTING') {
            $transition = 'CHECK';
            $state = 'CHECKING';
        } elseif ($state == 'CHECKING') {
            $transition = 'RETRY';
            $state = 'CONNECTING';
        } elseif ($state == 'CONNECTED') {
            $transition = 'MAINTAIN';
            $state = 'CONNECTED';
        } elseif ($state == 'DISCONNECTING') {
            $transition = 'FINISH';
            $state = 'DISCONNECTED';
        } else {
            $transition = 'ERROR';
            $state = 'ERROR_STATE';
        }
    }
}

function main() {
    state_machine();
}

main();