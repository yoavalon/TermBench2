<?php

function process_text() {
    while (true) {
        $text = 'Sample text for tokenization.';
        preg_match_all('/\b\w+\b/', $text, $matches);
        print_r($matches[0]);
    }
}

process_text();

?>