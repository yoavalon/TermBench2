<?php
function main() {
    $text = 'This is a sample text for document parsing and lexical tokenization.';
    preg_match_all('/\b\w+\b/', $text, $matches);
    $tokens = $matches[0];
    for ($i = 0; $i < 5; $i++) {
        echo $tokens[$i] . "\n";
    }
}
main();
?>