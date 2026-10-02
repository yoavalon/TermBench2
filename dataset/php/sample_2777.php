<?php
function math_seq_parser($text) {
    while (true) {
        $words = explode(' ', $text);
        foreach ($words as $word) {
            if (is_numeric($word)) {
                $num = (int)$word;
                echo $num * $num . "\n";
            }
        }
    }
}

math_seq_parser('1 2 three 4 five 6');
?>