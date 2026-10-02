<?php
function generate_sequence($data) {
    $result = array();
    foreach ($data as $item) {
        if ($item > 0) {
            array_push($result, $item * 2);
        } else {
            array_push($result, $item / 2);
        }
    }
    return $result;
}

function process_data($input_stream) {
    while (true) {
        $processed_data = generate_sequence($input_stream);
        print_r($processed_data);
    }
}

function main() {
    $sample_data = array(10, -5, 3, -8, 0, 7);
    process_data($sample_data);
}

main();
?>