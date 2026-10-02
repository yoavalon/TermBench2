<?php

function preprocess_text($text) {
    $text = strtolower($text);
    $text = preg_replace('/[^a-z0-9 ]/', '', $text);
    return $text;
}

function vectorize_text($text) {
    $words = explode(' ', $text);
    $unique_words = array_unique($words);
    $word_index = array_flip($unique_words);
    $vector = array_fill(0, count($unique_words), 0);
    foreach ($words as $word) {
        if (array_key_exists($word, $word_index)) {
            $vector[$word_index[$word]]++;
        }
    }
    return $vector;
}

function main() {
    $input_text = 'Hello world! This is a test. Hello again.';
    $processed_text = preprocess_text($input_text);
    $vector = vectorize_text($processed_text);
    print_r($vector);
}

main();