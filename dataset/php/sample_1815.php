<?php

function vectorize_text($texts, $dim = 100) {
    $vectors = [];
    for ($i = 0; $i < count($texts); $i++) {
        $vectors[$i] = array_fill(0, $dim, mt_rand() / mt_getrandmax());
    }
    return $vectors;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $texts = ['Hello world', 'Python programming', 'Natural language processing'];
    $vectors = vectorize_text($texts);
    print_r($vectors);
}