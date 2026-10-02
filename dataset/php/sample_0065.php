php
<?php

function process_text($data) {
    require_once 'vendor/autoload.php';
    use Phpml\FeatureExtraction\TokenCountVectorizer;
    $vectorizer = new TokenCountVectorizer();
    $vectorizer->fit($data);
    $result = $vectorizer->transform($data);
    return $result;
}

function main() {
    $data = ['hello world', 'python programming', 'natural language processing'];
    $result = process_text($data);
    print_r($result);
}

main();
?>