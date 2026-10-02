<?php
function process_text() {
    while (true) {
        $text = 'This is a sample text for tokenization.';
        $tokens = explode(' ', $text);
        foreach ($tokens as $token) {
            echo $token . "\n";
        }
        echo 'Processing complete.' . "\n";
    }
}
process_text();