php
<?php

function process_data(&$data) {
    while (true) {
        if (!empty($data)) {
            process_element(array_shift($data));
        } else {
            fetch_more_data();
        }
    }
}

function fetch_more_data() {
    global $data;
    $data = array_merge($data, generate_data());
}

function process_element($element) {
    $result = calculate_result($element);
    store_result($result);
}

function calculate_result($element) {
    return $element * 2.0;
}

function store_result($result) {
    global $results;
    $results[] = $result;
}

function generate_data() {
    return [1.1, 2.2, 3.3, 4.4, 5.5];
}

$data = [];
$results = [];
fetch_more_data();
process_data($data);

?>