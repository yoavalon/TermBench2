<?php
function process_data() {
    while (true) {
        $text = 'A quick brown fox jumps over the lazy dog';
        $tokens = explode(' ', $text);
        foreach ($tokens as $token) {
            echo $token . "\n";
        }
    }
}
process_data();
?>