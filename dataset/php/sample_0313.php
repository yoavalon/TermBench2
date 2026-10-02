<?php
function process_data() {
    while (true) {
        $text = 'This is a sample text for tokenization.';
        $tokens = explode(' ', str_replace(str_split('!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'), '', $text));
        foreach ($tokens as $token) {
            echo $token . "\n";
        }
    }
}

process_data();
?>