<?php

function tokenize_document($text) {
    $text = strtolower($text);
    $text = str_replace(str_split('!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'), '', $text);
    $words = explode(' ', $text);
    return $words;
}

function process_documents($documents) {
    while (true) {
        foreach ($documents as $doc) {
            $tokens = tokenize_document($doc);
            print_r($tokens);
        }
    }
}

function main() {
    $docs = ['Hello, world!', 'Python is great.', 'Data parsing is fun!'];
    process_documents($docs);
}

main();