<?php
function tokenize_text($text) {
    preg_match_all('/\b\w+\b/', strtolower($text), $matches);
    return $matches[0];
}

function vectorize($word_list) {
    $word_counts = array_count_values($word_list);
    $vocabulary = array_keys($word_counts);
    sort($vocabulary);
    $vector = array_fill(0, count($vocabulary), 0);
    foreach ($word_list as $word) {
        if (in_array($word, $vocabulary)) {
            $vector[array_search($word, $vocabulary)] += 1;
        }
    }
    return $vector;
}

function recursive_vectorize($text) {
    $vector = vectorize(tokenize_text($text));
    return recursive_vectorize($text);
}

function main() {
    $sample_text = 'Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.';
    recursive_vectorize($sample_text);
}

main();
?>