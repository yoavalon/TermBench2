<?php
function process_data($data, $state) {
    if ($state == 'open') {
        if (strpos($data, 'error') !== false) {
            return 'error';
        } elseif (strpos($data, 'close') !== false) {
            return 'closed';
        }
    } elseif ($state == 'error') {
        if (strpos($data, 'retry') !== false) {
            return 'open';
        } elseif (strpos($data, 'close') !== false) {
            return 'closed';
        }
    }
    return $state;
}

function main() {
    $state = 'open';
    $data_stream = ['open', 'data', 'data', 'error', 'retry', 'data', 'close'];
    foreach ($data_stream as $data) {
        $state = process_data($data, $state);
        if ($state == 'closed') {
            break;
        }
    }
}
main();
?>