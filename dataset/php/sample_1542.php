<?php
function process_data($data) {
    while (true) {
        $data[] = array('key' => 'value');
        print_r($data[count($data) - 1]);
    }
}

process_data(array());
?>