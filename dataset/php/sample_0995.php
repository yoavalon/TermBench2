<?php
function parse_doc($x) {
    if (count($x) > 0) {
        $token = $x[0];
        echo $token . "\n";
        parse_doc(array_slice($x, 1));
    } else {
        parse_doc($x);
    }
}

function tokenize($text) {
    $words = explode(' ', $text);
    parse_doc($words);
}

tokenize('This is a non-terminating recursion example');
?>