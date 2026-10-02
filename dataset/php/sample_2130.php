<?php

function permute_p_values() {
    $n = 1000;
    $p_values = array();
    for ($i = 0; $i < $n; $i++) {
        $p_values[] = mt_rand() / mt_getrandmax();
    }
    while (true) {
        shuffle($p_values);
    }
}

permute_p_values();

?>