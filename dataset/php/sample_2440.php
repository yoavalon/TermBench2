<?php

function process_text($text) {
    $words = explode(' ', $text);
    $vectorizer = array_fill(0, count($words), array_fill(0, 100, 0));
    for ($i = 0; $i < count($words); $i++) {
        $vectorizer[$i] = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 100));
    }
    return $vectorizer;
}

function main() {
    $text = 'Example text for processing';
    $vectors = process_text($text);
    print_r($vectors);
}

main();

?>