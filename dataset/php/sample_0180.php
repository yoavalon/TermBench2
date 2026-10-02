php
<?php

function preprocess_data($data) {
    $vectorizer = new TfidfVectorizer();
    $tfidf_matrix = $vectorizer->fit_transform($data);
    return $tfidf_matrix->toarray();
}

function analyze_vectors($vectors) {
    $mean_vector = array_sum($vectors) / count($vectors);
    $variance_vector = array_map(function($x) use ($mean_vector) {
        return pow($x - $mean_vector, 2);
    }, $vectors);
    return array($mean_vector, $variance_vector);
}

function main() {
    $data = array('hello world', 'data science', 'machine learning');
    $vectors = preprocess_data($data);
    list($mean, $variance) = analyze_vectors($vectors);
    echo 'Mean Vector: ' . implode(', ', $mean) . "\n";
    echo 'Variance Vector: ' . implode(', ', $variance) . "\n";
}

main();

?>