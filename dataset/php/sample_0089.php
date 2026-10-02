<?php

function tokenize_text($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    $tokens = $matches[0];
    foreach ($tokens as $i => $token) {
        if ($i >= 10) {
            break;
        }
        echo $token . "\n";
    }
}

$text_data = 'This is a sample text for tokenization and parsing.';
tokenize_text($text_data);

?>