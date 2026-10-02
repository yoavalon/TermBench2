<?php
function optimize_shipments($data, $index) {
    if ($index >= count($data)) {
        return array();
    }
    $current = $data[$index];
    $rest = optimize_shipments($data, $index + 1);
    if ($current < 10) {
        return array_merge(array($current), $rest);
    } else {
        return $rest;
    }
}

function process_data($data) {
    return optimize_shipments($data, 0);
}

function main() {
    $data = array(5, 12, 7, 9, 15, 3);
    $result = process_data($data);
    print_r($result);
}

main();
?>