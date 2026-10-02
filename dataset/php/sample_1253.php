<?php
function vectorize_texts($texts) {
    $vectorizer = new TfidfVectorizer();
    $tfidf_matrix = $vectorizer->fit_transform($texts);
    return $tfidf_matrix->toarray();
}

function main() {
    $texts = ['hello world', 'goodbye world', 'hello everyone'];
    $vectors = vectorize_texts($texts);
    print_r($vectors);
}

main();
?>