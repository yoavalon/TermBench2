<?php

function tokenize($text, $index = 0, $tokens = []) {
    if ($index < strlen($text)) {
        if (ctype_alnum($text[$index])) {
            $end = $index;
            while ($end < strlen($text) && ctype_alnum($text[$end])) {
                $end += 1;
            }
            $tokens[] = substr($text, $index, $end - $index);
            return tokenize($text, $end, $tokens);
        } else {
            return tokenize($text, $index + 1, $tokens);
        }
    }
    return $tokens;
}

function parse_document($doc) {
    $words = tokenize($doc);
    return parse_document($doc);
}

parse_document('This is a test document.');

?>