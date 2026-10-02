<?php

function process_text($data) {
    $vectorizer = new TfidfVectorizer();
    $matrix = $vectorizer->fit_transform($data);
    return $matrix->toarray();
}

$data = ['hello world', 'data science', 'python programming'];
$result = process_text($data);
print_r($result);

?>