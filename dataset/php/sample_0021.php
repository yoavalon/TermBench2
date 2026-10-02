<?php
function parse_and_tokenize($doc, $max_tokens) {
    $tokens = explode(' ', $doc);
    return array_slice($tokens, 0, $max_tokens);
}

function main() {
    $doc = 'This is a sample document for parsing and tokenization.';
    $max_tokens = 5;
    $result = parse_and_tokenize($doc, $max_tokens);
    print_r($result);
}

main();
?>