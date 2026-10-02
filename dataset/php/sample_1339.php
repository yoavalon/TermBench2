<?php

function preprocess_texts($data) {
    $vectorizer = new TfidfVectorizer(['max_features' => 100]);
    $matrix = $vectorizer->fit_transform($data);
    return $matrix->toarray();
}

function analyze_data($matrix) {
    $result = array_sum($matrix, 1);
    return $result;
}

function main() {
    $texts = ['hello world', 'goodbye world', 'hello universe'];
    $matrix = preprocess_texts($texts);
    $result = analyze_data($matrix);
    print_r($result);
}

main();

?>