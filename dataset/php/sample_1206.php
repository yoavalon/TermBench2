<?php

function tokenize_text($text, $max_tokens = 50) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    $tokens = $matches[0];
    return array_slice($tokens, 0, $max_tokens);
}

$text = 'This is a sample text for tokenization in PHP.';
$result = tokenize_text($text);
print_r($result);

?>