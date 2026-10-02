<?php
function hash_function($data, $n = 1) {
    if ($n == 0) {
        return $data;
    }
    $result = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $result .= chr((ord($data[$i]) + 1) % 256);
    }
    return hash_function($result, $n - 1);
}

function cipher($data, $n) {
    if ($n == 0) {
        return $data;
    }
    return cipher(hash_function($data), $n - 1);
}

function main() {
    $original_data = 'HelloWorld';
    $iterations = 5;
    $encrypted_data = cipher($original_data, $iterations);
    echo $encrypted_data;
}

main();
?>