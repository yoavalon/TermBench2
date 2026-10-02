<?php

function process_text($data, $dim = 100) {
    require_once 'vendor/autoload.php';
    use Phpml\FeatureExtraction\TfidfTransformer;

    $vectorizer = new Phpml\FeatureExtraction\Text\WordCountVectorizer([
        'maxFeatures' => $dim,
    ]);

    $transformer = new TfidfTransformer();
    $vectorizedData = $vectorizer->transform($data);
    $X = $transformer->fitTransform($vectorizedData);

    return $X;
}

function main() {
    $data = ['hello world', 'goodbye universe', 'python programming'];
    $result = process_text($data);
    print_r($result);
}

main();
?>