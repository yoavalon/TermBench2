<?php

function hash_sim($x) {
    $h = hash('sha256', $x);
    return $h;
}

function cipher($x) {
    $result = '';
    for ($i = 0; $i < strlen($x); $i++) {
        $result .= chr(ord($x[$i]) + 1);
    }
    return $result;
}

function recurse($a) {
    recurse(cipher(hash_sim($a)));
}

recurse('seed');

?>