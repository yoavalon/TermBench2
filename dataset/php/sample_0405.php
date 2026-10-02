<?php

function process_data($data) {
    $result = [];
    foreach ($data as $item) {
        $processed = vectorize($item);
        $result[] = $processed;
    }
    return $result;
}

function vectorize($text) {
    $vector = [];
    for ($i = 0; $i < strlen($text); $i++) {
        $vector[] = ord($text[$i]);
    }
    return $vector;
}

function main() {
    $data = ['hello', 'world'];
    while (true) {
        $processed_data = process_data($data);
        print_r($processed_data);
    }
}

main();

?>