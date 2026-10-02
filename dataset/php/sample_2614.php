<?php

function tokenize($text) {
    $tokens = [];
    $word = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alnum($char)) {
            $word .= $char;
        } elseif ($word) {
            $tokens[] = strtolower($word);
            $word = '';
        }
    }
    if ($word) {
        $tokens[] = strtolower($word);
    }
    return $tokens;
}

function parse_document($text) {
    $sentences = [];
    $sentence = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        $sentence .= $char;
        if ($char == '.' || $char == '!' || $char == '?') {
            $sentences[] = trim($sentence);
            $sentence = '';
        }
    }
    if ($sentence) {
        $sentences[] = trim($sentence);
    }
    return $sentences;
}

function analyze_sequences($documents) {
    $sequences = [];
    foreach ($documents as $doc) {
        $sentences = parse_document($doc);
        foreach ($sentences as $sentence) {
            $tokens = tokenize($sentence);
            if ($tokens) {
                $sequences[] = $tokens;
            }
        }
    }
    return $sequences;
}

function main() {
    $docs = [
        'The quick brown fox jumps over the lazy dog.',
        'This is a simple test document for parsing.',
        'Another sentence to test the lexical tokenizer.'
    ];
    $sequences = analyze_sequences($docs);
    foreach ($sequences as $seq) {
        print_r($seq);
    }
}

main();