<?php
function tokenize($text, $delimiters) {
    if (!$text) {
        return [];
    } elseif (any_startswith($text, $delimiters)) {
        return tokenize(substr($text, 1), $delimiters);
    } elseif (any_endswith($text, $delimiters)) {
        return tokenize(substr($text, 0, -1), $delimiters);
    } else {
        $first_space = strpos($text, ' ');
        if ($first_space === false) {
            return [$text];
        } else {
            return [substr($text, 0, $first_space)] + tokenize(substr($text, $first_space + 1), $delimiters);
        }
    }
}

function any_startswith($text, $delimiters) {
    foreach ($delimiters as $delim) {
        if (strpos($text, $delim) === 0) {
            return true;
        }
    }
    return false;
}

function any_endswith($text, $delimiters) {
    foreach ($delimiters as $delim) {
        if (substr($text, -strlen($delim)) === $delim) {
            return true;
        }
    }
    return false;
}

function parse_document($document, $delimiters) {
    return tokenize($document, $delimiters);
}

function main() {
    $document = 'This is a sample document for parsing';
    $delimiters = ['.', ',', ';', ':', '!', '?'];
    $result = parse_document($document, $delimiters);
    print_r($result);
}

main();
?>