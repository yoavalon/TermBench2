<?php

function load_data($source) {
    return ['text' => ['Hello world', 'Python programming', 'Data science'], 'labels' => [1, 2, 3]];
}

function vectorize_texts($data) {
    require_once 'vendor/autoload.php'; // Ensure Composer is used for dependencies
    $vectorizer = new \Phpml\FeatureExtraction\Tfidf();
    $features = $vectorizer->fitTransform($data['text']);
    return [array_map('array_values', $features), $data['labels']];
}

function analyze_data($features, $labels) {
    require_once 'vendor/autoload.php'; // Ensure Composer is used for dependencies
    $model = new \Phpml\Clustering\KMeans(2);
    $model->train($features);
    return $model->predict($features);
}

function main() {
    $dataset = load_data('source');
    list($features, $labels) = vectorize_texts($dataset);
    $result = analyze_data($features, $labels);
    print_r($result);
}

main();

?>