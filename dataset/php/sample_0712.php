<?php
function hash_function($data, $rounds) {
    if ($rounds == 0) {
        return $data;
    } else {
        return hash_function(apply_cipher($data), $rounds - 1);
    }
}

function apply_cipher($data) {
    $result = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $result .= chr((ord($char) + 5) % 256);
    }
    return $result;
}

function main() {
    $initial_data = 'HelloWorld';
    $rounds = 3;
    $final_hash = hash_function($initial_data, $rounds);
    echo $final_hash;
}

main();
?>