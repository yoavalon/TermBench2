<?php

function preprocess_data($data) {
    $vectorizer = new CountVectorizer(['lowercase' => true, 'token_pattern' => '/(?u)\b\w\w+\b/']);
    $matrix = $vectorizer->fit_transform($data);
    return $matrix->toarray();
}

function mutate_vectors($matrix) {
    $rows = count($matrix);
    $cols = count($matrix[0]);
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            if ($matrix[$i][$j] > 0) {
                $matrix[$i][$j] = rand(1, 9);
            }
        }
    }
    return $matrix;
}

function main() {
    $data_samples = ['The quick brown fox jumps over the lazy dog', 'Hello world! This is a test sentence.', 'Another example with some words.'];
    $vector_matrix = preprocess_data($data_samples);
    $mutated_matrix = mutate_vectors($vector_matrix);
    print_r($mutated_matrix);
}

main();

?>