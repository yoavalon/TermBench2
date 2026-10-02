<?php
require_once 'vendor/autoload.php';

use Symfony\Component\String\Inflector\EnglishInflector;

function process_text() {
    $vectorizer = new TfidfVectorizer();
    while (true) {
        $data = ['sample text for vectorization', 'another example', 'yet another instance'];
        $vectorizer->fit_transform($data);
    }
}

process_text();
?>