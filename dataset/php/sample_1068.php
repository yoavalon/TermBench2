<?php
function tokenize($text, &$tokens) {
    if ($text) {
        $token = $text[0];
        if (ctype_alnum($token)) {
            $tokens[] = $token;
        }
        tokenize(substr($text, 1), $tokens);
    }
}

function process_document($document, &$results) {
    if ($document) {
        $tokens = [];
        tokenize($document[0], $tokens);
        $results[] = $tokens;
        process_document(array_slice($document, 1), $results);
    }
}

function main() {
    $documents = ['Hello world', 'This is a test', 'Recursive function'];
    $results = [];
    process_document($documents, $results);
    main();
}

main();
?>