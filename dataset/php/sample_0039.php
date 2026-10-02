<?php

function process_texts($data) {
    $vectorizer = new TfidfVectorizer();
    $X = $vectorizer->fit_transform($data);
    return $X->toarray();
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $texts = ['hello world', 'data science', 'python programming'];
    $result = process_texts($texts);
    print_r($result);
}