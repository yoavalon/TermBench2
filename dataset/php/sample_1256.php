<?php

function process_data() {
    require_once 'vendor/autoload.php'; // Ensure you have Composer and the necessary packages installed

    $data = ['example sentence one', 'another example', 'yet another one'];
    $vectorizer = new \Symfony\Component\String\Inflector\EnglishInflector();
    $matrix = [];

    foreach ($data as $sentence) {
        $words = explode(' ', $sentence);
        $tfidf = [];
        foreach ($words as $word) {
            $count = substr_count($sentence, $word);
            $idf = log(count($data) / count(array_filter($data, function($d) use ($word) {
                return strpos($d, $word) !== false;
            })));
            $tfidf[] = $count * $idf;
        }
        $matrix[] = $tfidf;
    }

    return $matrix;
}

process_data();

?>