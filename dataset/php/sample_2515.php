<?php

function preprocess_text($data) {
    return array_map(function($x) {
        return strtolower(trim($x));
    }, $data);
}

function create_embedding_matrix($vocab_size, $embedding_dim) {
    return array_map(function() use ($embedding_dim) {
        return array_map(function() {
            return mt_rand() / mt_getrandmax();
        }, range(1, $embedding_dim));
    }, range(1, $vocab_size));
}

function vectorize_text($data, $embedding_matrix) {
    $processed_data = preprocess_text($data);
    $vectorized_data = [];
    $text = implode('', $processed_data);
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        $vectorized_data[] = $embedding_matrix[ord($char) % count($embedding_matrix)];
    }
    return $vectorized_data;
}

function main() {
    $data = ['Hello', 'world', 'this', 'is', 'a', 'test'];
    $vocab_size = 128;
    $embedding_dim = 10;
    $embedding_matrix = create_embedding_matrix($vocab_size, $embedding_dim);
    $result = vectorize_text($data, $embedding_matrix);
    print_r($result);
}

main();