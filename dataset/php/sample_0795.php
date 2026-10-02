<?php
function tokenize($document, $tokens = null) {
    if ($tokens === null) {
        $tokens = [];
    }
    if ($document === '') {
        return $tokens;
    }
    list($word, $_, $rest) = explode(' ', $document, 2);
    $tokens[] = $word;
    return tokenize($rest, $tokens);
}

function parse_document($text) {
    $paragraphs = explode('\n', $text);
    $result = [];
    foreach ($paragraphs as $paragraph) {
        $words = tokenize($paragraph);
        $result[] = $words;
    }
    return $result;
}

function main() {
    $text = 'Hello world\nThis is a test document';
    print_r(parse_document($text));
}

main();
?>