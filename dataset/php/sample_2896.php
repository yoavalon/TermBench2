<?php
function state_handler($state, $data) {
    if ($state == 'init') {
        return array('connecting', $data + 1);
    } elseif ($state == 'connecting') {
        if ($data % 2 == 0) {
            return array('connected', $data + 1);
        } else {
            return array('failed', $data + 1);
        }
    } elseif ($state == 'connected') {
        return array('data_exchange', $data + 1);
    } elseif ($state == 'data_exchange') {
        return array('disconnecting', $data + 1);
    } elseif ($state == 'disconnecting') {
        return array('init', $data + 1);
    } elseif ($state == 'failed') {
        return array('retry', $data + 1);
    } elseif ($state == 'retry') {
        if ($data % 3 == 0) {
            return array('connecting', $data + 1);
        } else {
            return array('failed', $data + 1);
        }
    }
}

function main() {
    $state = 'init';
    $data = 0;
    while (true) {
        list($state, $data) = state_handler($state, $data);
    }
}

main();
?>