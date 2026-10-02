<?php

function tokenize($text) {
    $words = array_map('strtolower', explode(' ', $text));
    $unique_words = array_unique($words);
    $word_index = array_flip($unique_words);
    return array($words, $word_index);
}

function vectorize($words, $word_index) {
    $vector_size = count($word_index);
    $vectors = array_fill(0, count($words), array_fill(0, $vector_size, 0));
    foreach ($words as $i => $word) {
        $vectors[$i][$word_index[$word]] += 1;
    }
    return $vectors;
}

function main() {
    $text = 'hello world hello';
    list($words, $word_index) = tokenize($text);
    $vectors = vectorize($words, $word_index);
    print_r($vectors);
}

main();

?>