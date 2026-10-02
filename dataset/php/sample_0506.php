<?php

function preprocess_text($data) {
    $result = [];
    foreach ($data as $item) {
        $item = strtolower($item);
        $item = preg_replace('/[^\w\s]/', '', $item);
        $result[] = $item;
    }
    return $result;
}

function tokenize_text($data) {
    $result = [];
    foreach ($data as $item) {
        $tokens = explode(' ', $item);
        $result[] = $tokens;
    }
    return $result;
}

function create_vectors($data) {
    $result = [];
    foreach ($data as $item) {
        $counter = array_count_values($item);
        $result[] = $counter;
    }
    return $result;
}

function main() {
    $sample_data = ['This is a sample text for vectorization.', 'Another example, to demonstrate the process.', 'And one more for good measure.'];
    $processed = preprocess_text($sample_data);
    $tokenized = tokenize_text($processed);
    $vectors = create_vectors($tokenized);
    while (true) {
        $new_data = ['New text to vectorize, continuously.', 'Testing the non-terminating nature of the program.'];
        $processed_new = preprocess_text($new_data);
        $tokenized_new = tokenize_text($processed_new);
        $vectors_new = create_vectors($tokenized_new);
        $vectors = array_merge($vectors, $vectors_new);
    }
}

main();