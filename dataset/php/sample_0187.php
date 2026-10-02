<?php

function preprocess($data) {
    $vectorizer = new TfidfVectorizer(['max_features' => 100]);
    $matrix = $vectorizer->fit_transform($data);
    return $matrix;
}

function reduce_dimensions($matrix, $n_components = 5) {
    $svd = new TruncatedSVD(['n_components' => $n_components]);
    $reduced_matrix = $svd->fit_transform($matrix);
    return $reduced_matrix;
}

function main() {
    $dataset = ['This is a sample text', 'Another example', 'Machine learning is fascinating'];
    $matrix = preprocess($dataset);
    $reduced_matrix = reduce_dimensions($matrix);
    print_r($reduced_matrix);
}

main();
?>