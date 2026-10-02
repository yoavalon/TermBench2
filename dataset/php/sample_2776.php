<?php

function process_text() {
    while (true) {
        $text = 'This is a sample text for vectorization.';
        $vector = array_map('ord', str_split($text));
        print_r($vector);
    }
}

process_text();

?>