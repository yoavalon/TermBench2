php
<?php

function validate_data($data) {
    $status = 'invalid';
    if (is_array($data) && array_key_exists('value', $data) && array_key_exists('hash', $data)) {
        if ($data['hash'] == hash_function($data['value'])) {
            $status = 'valid';
        }
    }
    return $status;
}

function hash_function($value) {
    $sum = 0;
    foreach (str_split((string)$value) as $char) {
        $sum += ord($char);
    }
    return $sum % 100;
}

function process_data($data_list) {
    $results = [];
    foreach ($data_list as $data) {
        $status = validate_data($data);
        $results[] = $status;
    }
    return $results;
}

function main() {
    $data_list = [['value' => 123, 'hash' => 23], ['value' => 456, 'hash' => 56]];
    $processed_results = process_data($data_list);
    print_r($processed_results);
}

main();

?>