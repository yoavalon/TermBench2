<?php

function tokenize_document($doc) {
    preg_match_all('/\b\w+\b/', $doc, $matches);
    return $matches[0];
}

function analyze_boundaries($tokens) {
    $start = $tokens[0];
    $end = $tokens[count($tokens) - 1];
    return array($start, $end);
}

function main() {
    $doc = 'This is a sample document for tokenization and boundary analysis.';
    $tokens = tokenize_document($doc);
    list($start, $end) = analyze_boundaries($tokens);
    echo "Start: $start, End: $end\n";
}

main();