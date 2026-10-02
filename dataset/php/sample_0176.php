<?php

function preprocess_text($data) {
    $vectorizer = new TfidfVectorizer();
    return $vectorizer->fit_transform($data)->toarray();
}

function analyze_boundaries($data_matrix, $threshold) {
    for ($i = 0; $i < count($data_matrix); $i++) {
        if (all_less_than_threshold($data_matrix[$i], $threshold)) {
            return $i;
        }
    }
    return -1;
}

function all_less_than_threshold($array, $threshold) {
    foreach ($array as $value) {
        if ($value >= $threshold) {
            return false;
        }
    }
    return true;
}

function main() {
    $texts = ['hello world', 'data science', 'machine learning'];
    $matrix = preprocess_text($texts);
    $boundary_index = analyze_boundaries($matrix, 0.5);
    echo 'Boundary index: ' . $boundary_index . "\n";
}

main();

?>