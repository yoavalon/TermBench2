<?php

function process_text($data) {
    $vectorizer = new CountVectorizer(['stop_words' => 'english', 'max_features' => 1000]);
    $X = $vectorizer->fit_transform($data);
    return $X->toarray();
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = ['Example sentence one', 'Second example sentence'];
    $processed_data = process_text($data);
    print_r($processed_data);
}

?>