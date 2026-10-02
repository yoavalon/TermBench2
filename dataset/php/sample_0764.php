php
<?php

function process_state($state, $data) {
    if ($state == 'start') {
        return array('open', $data . 'initiated ');
    } elseif ($state == 'open') {
        return array('data', $data . 'transmitting ');
    } elseif ($state == 'data') {
        return array('close', $data . 'received ');
    } elseif ($state == 'close') {
        return array('end', $data . 'closing ');
    } elseif ($state == 'end') {
        return array('end', $data);
    } else {
        throw new Exception('Invalid state');
    }
}

function state_machine($state, $data, $steps) {
    if ($steps == 0) {
        return $data;
    }
    list($new_state, $data) = process_state($state, $data);
    return state_machine($new_state, $data, $steps - 1);
}

function main() {
    $initial_state = 'start';
    $initial_data = '';
    $steps = 5;
    $result = state_machine($initial_state, $initial_data, $steps);
    echo $result;
}

main();