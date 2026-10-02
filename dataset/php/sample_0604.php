<?php

function hash_cipher($data, $depth) {
    if ($depth == 0) {
        return $data;
    } else {
        return hash_cipher(hash('sha256', $data), $depth - 1);
    }
}

$result = hash_cipher('example_data', 3);
echo $result;

?>