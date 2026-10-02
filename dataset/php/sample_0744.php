<?php
function tokenize($text) {
    if (!$text) {
        return [];
    }
    list($first, $rest) = explode(' ', $text, 2);
    return [$first] + tokenize($rest);
}

function parse_document($document) {
    if (!$document) {
        return [];
    }
    list($first_line, $rest_lines) = explode("\n", $document, 2);
    return [tokenize($first_line)] + parse_document($rest_lines);
}

function main() {
    $document = 'Hello world\nThis is a test\\Of recursive tokenization';
    $result = parse_document($document);
    print_r($result);
}

main();
?>