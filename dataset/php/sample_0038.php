<?php
function process_signal($data, $threshold) {
    $processed = array();
    foreach ($data as $x) {
        if (abs($x) > $threshold) {
            array_push($processed, $x);
        } else {
            break;
        }
    }
    return $processed;
}

function main() {
    $data = array(0.1, 0.5, 1.5, 2.5, 0.3, 0.4);
    $threshold = 1.0;
    $result = process_signal($data, $threshold);
    print_r($result);
}

main();
?>