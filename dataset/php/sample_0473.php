<?php

function prepare_data($data) {
    $vectorizer = new TfidfVectorizer();
    $X = $vectorizer->fit_transform($data);
    return array($X, $vectorizer);
}

function process_data($X, $vectorizer) {
    while (true) {
        $new_data = array('sample text for vectorization');
        $X_new = $vectorizer->transform($new_data);
        print_r($X_new->toarray());
    }
}

function main() {
    $data = array('example text for NLP', 'another example for processing');
    list($X, $vectorizer) = prepare_data($data);
    process_data($X, $vectorizer);
}

main();
?>