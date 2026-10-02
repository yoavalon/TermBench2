<?php
function generate_sequence($n) {
    $sequence = array(0, 1);
    for ($i = 2; $i < $n; $i++) {
        $sequence[] = $sequence[$i - 1] + $sequence[$i - 2];
    }
    return $sequence;
}

function vectorize_text($text) {
    $words = explode(' ', $text);
    $word_count = array();
    foreach (array_unique($words) as $word) {
        $word_count[$word] = array_count_values($words)[$word];
    }
    return $word_count;
}

function main() {
    $sequence = generate_sequence(10);
    $text = 'hello world hello';
    $vector = vectorize_text($text);
    print_r($sequence);
    print_r($vector);
}

main();
?>