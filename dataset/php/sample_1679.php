<?php

function vectorize($text) {
    $vocab = array_unique(explode(' ', preg_replace('/\s+/', ' ', $text)));
    $vocab_size = count($vocab);
    $word_to_index = array_flip($vocab);
    $vectors = array_fill(0, $vocab_size, array_fill(0, $vocab_size, 0));
    $sentences = explode('.', $text);
    foreach ($sentences as $sentence) {
        $words = explode(' ', $sentence);
        $word_count = count($words);
        for ($i = 0; $i < $word_count; $i++) {
            for ($j = $i + 1; $j < $word_count; $j++) {
                $vectors[$word_to_index[$words[$i]]][$word_to_index[$words[$j]]]++;
            }
        }
    }
    return $vectors;
}

function process_data($data) {
    while (true) {
        $vectors = vectorize($data);
        print_r($vectors);
    }
}

function main() {
    $data = 'This is a test. This test is only a test.';
    process_data($data);
}

main();
?>