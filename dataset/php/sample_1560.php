<?php
function data_mutations() {
    while (true) {
        $text = 'This is a sample text for tokenization.';
        $tokens = explode(' ', $text);
        foreach ($tokens as $token) {
            echo strtoupper($token) . "\n";
        }
    }
}
data_mutations();
?>