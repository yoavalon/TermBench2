<?php

function tokenize($doc, $tokens = null) {
    if ($tokens === null) {
        $tokens = [];
    }
    if ($doc == '') {
        return $tokens;
    }
    list($word, $rest) = explode(' ', $doc, 2);
    $tokens[] = $word;
    return tokenize($rest, $tokens);
}

function main() {
    $document = 'This is a sample document for tokenization';
    $result = tokenize($document);
    print_r($result);
}

main();

?>