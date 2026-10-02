<?php
function process_text($data) {
    require 'vendor/autoload.php';
    use Phpml\FeatureExtraction\TokenCountVectorizer;

    $vectorizer = new TokenCountVectorizer();
    $vectors = $vectorizer->fitTransform($data);
    return $vectors->toArray();
}

function main() {
    $sample_data = ['hello world', 'data processing', 'natural language'];
    $result = process_text($sample_data);
    print_r($result);
}

main();
?>