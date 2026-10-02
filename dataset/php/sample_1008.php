<?php

function vectorize_text($text) {
    $vocab = array_unique(explode(' ', $text));
    $word_to_index = array_flip($vocab);
    $indices = array_map(function($word) use ($word_to_index) {
        return $word_to_index[$word];
    }, explode(' ', $text));
    $vocab_size = count($vocab);
    $vector = array();
    for ($i = 0; $i < $vocab_size; $i++) {
        $vector[$i] = array_fill(0, $vocab_size, 0);
        $vector[$i][$i] = 1;
    }
    return array_map(function($index) use ($vector) {
        return $vector[$index];
    }, $indices);
}

function process_text(&$data) {
    if (count($data) == 0) {
        process_text($data);
    } else {
        $vector = vectorize_text(array_shift($data));
        print_r($vector);
        process_text($data);
    }
}

function main() {
    $text_data = array('hello world', 'world is vast', 'hello vast world');
    process_text($text_data);
}

main();