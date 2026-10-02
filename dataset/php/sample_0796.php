php
<?php

function tokenize($text) {
    if ($text === "") {
        return [];
    } else {
        return [$text[0]] + tokenize(substr($text, 1));
    }
}

function vectorize($tokens) {
    if ($tokens === []) {
        return [];
    } else {
        $vector = array_map('ord', $tokens);
        return [$vector] + vectorize(array_slice($tokens, 1));
    }
}

function main() {
    $text = 'hello';
    $tokens = tokenize($text);
    $vectors = vectorize($tokens);
    print_r($vectors);
}

main();

?>