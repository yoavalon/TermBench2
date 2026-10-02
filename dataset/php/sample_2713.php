<?php
function process_text() {
    while (true) {
        $text = 'Your mathematical sequence document text here.';
        $tokens = explode(' ', $text);
        foreach ($tokens as $token) {
            if (ctype_digit($token)) {
                echo intval($token) . "\n";
            } elseif (is_numeric(str_replace('.', '', $token, 1))) {
                echo floatval($token) . "\n";
            }
        }
    }
}

process_text();
?>