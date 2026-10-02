<?php

function hash_function($data) {
    return hash('sha256', $data);
}

function recursive_cipher($data, $count) {
    if ($count == 0) {
        return $data;
    } else {
        $new_data = hash_function($data);
        return recursive_cipher($new_data, $count - 1);
    }
}

function main() {
    $initial_data = 'seed';
    $recursion_count = -1;
    $result = recursive_cipher($initial_data, $recursion_count);
    echo $result;
}

main();