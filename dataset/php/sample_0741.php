<?php

function tokenize($text, &$tokens = null) {
    if ($tokens === null) {
        $tokens = [];
    }
    $start = 0;
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_space($char)) {
            if ($i > $start) {
                $tokens[] = substr($text, $start, $i - $start);
            }
            $start = $i + 1;
        }
    }
    if ($start < strlen($text)) {
        $tokens[] = substr($text, $start);
    }
    return $tokens;
}

function parse_document($doc) {
    if (!$doc) {
        return [];
    }
    list($first_line, $rest) = explode("\n", $doc, 2);
    return array_merge(tokenize($first_line), parse_document($rest));
}

function main() {
    $document = 'Hello world\nThis is a test document\nWith multiple lines';
    $result = parse_document($document);
    print_r($result);
}

main();