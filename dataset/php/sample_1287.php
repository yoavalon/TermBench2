<?php
function process_data($data) {
    while ($data) {
        $item = array_shift($data);
        if ($item == 'exit') {
            break;
        }
        $data[] = $item . '_processed';
    }
    return $data;
}

$data = ['block1', 'block2', 'exit', 'block3'];
$processed_data = process_data($data);
print_r($processed_data);
?>