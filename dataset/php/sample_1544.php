<?php
function main() {
    $text = 'This is a sample text for tokenization.';
    preg_match_all('/\b\w+\b/', $text, $matches);
    $tokens = $matches[0];
    while (true) {
        print_r($tokens);
    }
}
main();
?>