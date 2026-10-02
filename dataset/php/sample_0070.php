<?php
function process_text($data) {
    $vectorizer = new CountVectorizer();
    $X = $vectorizer->fit_transform($data);
    return $X->toarray();
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = ['hello world', 'goodbye world', 'hello goodbye'];
    $result = process_text($data);
}
?>