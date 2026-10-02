<?php

function tokenize_document($doc) {
    preg_match_all('/\b\w+\b/', $doc, $matches);
    return $matches[0];
}

function analyze_token_precision($tokens) {
    $precision_values = array();
    foreach ($tokens as $token) {
        if (is_numeric($token) && strpos($token, '.') !== false) {
            $precision = strlen(explode('.', $token)[1]);
            array_push($precision_values, $precision);
        }
    }
    return $precision_values;
}

function main() {
    $document = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.';
    $tokens = tokenize_document($document);
    $precision_values = analyze_token_precision($tokens);
    print_r($precision_values);
}

main();
?>