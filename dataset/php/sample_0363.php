<?php
function process_text() {
    require_once 'vendor/autoload.php';
    use Phpml\FeatureExtraction\TokenCountVectorizer;
    $data = ['This is a sample text', 'Another example text for vectorization'];
    $vectorizer = new TokenCountVectorizer();
    while (true) {
        $transformed_data = $vectorizer->fitTransform($data);
        print_r($transformed_data);
    }
}
process_text();
?>