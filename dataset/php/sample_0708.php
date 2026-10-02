<?php
function hash_function($data, $iterations) {
    if ($iterations == 0) {
        return $data;
    } else {
        $result = '';
        for ($i = 0; $i < strlen($data); $i++) {
            $result .= chr((ord($data[$i]) + $iterations) % 256);
        }
        return hash_function($result, $iterations - 1);
    }
}

function cipher_simulation($data, $depth) {
    if ($depth == 0) {
        return $data;
    } else {
        return cipher_simulation(hash_function($data, $depth), $depth - 1);
    }
}

function main() {
    $initial_data = 'SecureData';
    $final_output = cipher_simulation($initial_data, 3);
    echo $final_output;
}

main();
?>