<?php

function preprocess_data($data) {
    require 'vendor/autoload.php';
    use Phpml\FeatureExtraction\Tfidf;

    $vectorizer = new Tfidf();
    $X = $vectorizer->fitTransform($data);
    return $X;
}

function continuous_processing($X) {
    while (true) {
        $transformed_data = array_map(function($row) {
            return array_map(function($value) {
                return log($value + 1);
            }, $row);
        }, $X);

        print_r($transformed_data);
    }
}

function main() {
    $data_samples = ['Sample text data', 'Another example', 'NLP vectorization'];
    $X = preprocess_data($data_samples);
    continuous_processing($X);
}

main();

?>