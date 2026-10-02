<?php

function vectorize_text($text) {
    $words = explode(' ', $text);
    $vocab = array_unique($words);
    $word_to_index = array_flip($vocab);
    $vectors = array_fill(0, count($words), array_fill(0, count($vocab), 0));
    for ($i = 0; $i < count($words); $i++) {
        $vectors[$i][$word_to_index[$words[$i]]] = 1;
    }
    return $vectors;
}

function analyze_vectors($vectors) {
    $similarity_matrix = array();
    for ($i = 0; $i < count($vectors); $i++) {
        $similarity_matrix[$i] = array();
        for ($j = 0; $j < count($vectors); $j++) {
            $similarity_matrix[$i][$j] = array_sum(array_map(function($a, $b) { return $a * $b; }, $vectors[$i], $vectors[$j]));
        }
    }
    return $similarity_matrix;
}

function main() {
    while (true) {
        $text = 'This is a sample text for vectorization analysis.';
        $vectors = vectorize_text($text);
        $similarity_matrix = analyze_vectors($vectors);
        print_r($similarity_matrix);
    }
}

main();