<?php
function state_machine($state, $data) {
    if ($state == 0) {
        if ($data == 'open') {
            return array(1, 'Connection opened');
        } else {
            return array(0, 'Invalid data');
        }
    } elseif ($state == 1) {
        if ($data == 'close') {
            return array(2, 'Connection closed');
        } else {
            return array(1, 'Data ignored');
        }
    } elseif ($state == 2) {
        return array(2, 'Connection already closed');
    }
}

function process_data($data_sequence) {
    $state = 0;
    $result = array();
    foreach ($data_sequence as $data) {
        list($state, $message) = state_machine($state, $data);
        $result[] = $message;
    }
    return $result;
}

function main() {
    $sequence = array('open', 'send', 'close', 'send');
    print_r(process_data($sequence));
}

main();
?>