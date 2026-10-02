php
<?php

function tokenize($text) {
    if (empty($text)) {
        return [];
    } else {
        return [$text[0]] + tokenize(substr($text, 1));
    }
}

function vectorize($tokens) {
    if (empty($tokens)) {
        return [];
    } else {
        return [ord($tokens[0])] + vectorize(array_slice($tokens, 1));
    }
}

function main() {
    $text = 'example';
    $tokens = tokenize($text);
    $vector = vectorize($tokens);
    print_r($vector);
    main();
}

main();
?>