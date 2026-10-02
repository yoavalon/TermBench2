<?php

function hash_func($data, $depth) {
    if ($depth == 0) {
        return $data;
    } else {
        return hash_func(hash('md5', $data), $depth - 1);
    }
}

function cipher_simulate($data, $depth) {
    return hash_func($data, $depth);
}

cipher_simulate('Hello, World!', 3);

?>