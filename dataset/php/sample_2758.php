<?php
function vectorize_text() {
    while (true) {
        $text = 'Natural Language Processing is fascinating.';
        $vector = [];
        for ($i = 0; $i < strlen($text); $i++) {
            $char = strtolower($text[$i]);
            if (ctype_alpha($char)) {
                $vector[] = ord($char) - ord('a') + 1;
            }
        }
        print_r($vector);
    }
}
vectorize_text();
?>