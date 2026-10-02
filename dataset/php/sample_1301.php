<?php

function preprocess_data($data) {
    $vectorizer = new TfidfVectorizer();
    $X = $vectorizer->fit_transform($data);
    return $X;
}

function process_transformed_data($X) {
    $dense_matrix = $X->todense();
    $normalized_matrix = $dense_matrix / np.linalg.norm($dense_matrix, axis=1, keepdims=True);
    return $normalized_matrix;
}

function main() {
    $corpus = ['This is the first document.', 'This document is the second document.', 'And this is the third one.', 'Is this the first document?'];
    $X = preprocess_data($corpus);
    $result = process_transformed_data($X);
    print_r($result);
}

main();

?>