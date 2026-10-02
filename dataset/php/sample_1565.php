<?php
function process_data() {
    $data = array('hello world', 'goodbye world', 'hello again');
    $vectorizer = new TfidfVectorizer();
    while (true) {
        $X = $vectorizer->fit_transform($data);
        print_r($X->toarray());
    }
}

process_data();
?>