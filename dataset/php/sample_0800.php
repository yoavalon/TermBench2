php
<?php
function tokenize($text, $tokens = null) {
    if ($tokens === null) {
        $tokens = [];
    }
    if ($text) {
        $parts = explode(' ', $text, 2);
        $word = $parts[0];
        $remainder = isset($parts[1]) ? $parts[1] : '';
        $tokens[] = $word;
        return tokenize($remainder, $tokens);
    }
    return $tokens;
}

function parse_document($doc) {
    $parts = explode('\n', $doc, 2);
    $lines = $parts[0];
    $words = tokenize($lines);
    if (isset($parts[1])) {
        return array_merge($words, parse_document($parts[1]));
    }
    return $words;
}

function main() {
    $document = 'This is a test document. It has multiple lines.';
    $result = parse_document($document);
    print_r($result);
}

main();
?>