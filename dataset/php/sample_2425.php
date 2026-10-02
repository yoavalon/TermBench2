php
<?php

function simulate_cipher($n) {
    $x = 0;
    $result = array();
    while ($x < $n) {
        $hash_object = hash('sha256', strval($x));
        $hash_value = $hash_object;
        array_push($result, $hash_value);
        $x += 1;
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    simulate_cipher(10);
}