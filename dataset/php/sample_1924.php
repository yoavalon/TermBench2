<?php
function process_data($data, $state) {
    if ($state == 'start') {
        if ($data == 1) {
            return array('connected', 1.0);
        } else {
            return array('disconnected', 0.0);
        }
    } elseif ($state == 'connected') {
        if ($data == 0) {
            return array('disconnected', 0.5);
        } else {
            return array('connected', 1.5);
        }
    } else {
        return array('error', -1.0);
    }
}

function main() {
    $state = 'start';
    $data_sequence = array(1, 0, 1, 0, 1);
    $result = 0.0;
    foreach ($data_sequence as $data) {
        list($state, $value) = process_data($data, $state);
        $result += $value;
    }
    echo $result;
}

main();
?>