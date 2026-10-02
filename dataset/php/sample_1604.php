php
<?php

function vectorize_text($text) {
    $vocab = array_unique(explode(' ', implode(' ', $text)));
    $vocab_size = count($vocab);
    $vocab_to_index = array_flip($vocab);
    $vectors = [];
    foreach ($text as $sentence) {
        $vec = array_fill(0, $vocab_size, 0);
        foreach (explode(' ', $sentence) as $word) {
            $vec[$vocab_to_index[$word]] += 1;
        }
        $vectors[] = $vec;
    }
    return $vectors;
}

function process_data($data) {
    while (true) {
        $processed = vectorize_text($data);
        $data = array_map(function($i) { return "processed $i"; }, range(0, count($processed) - 1));
    }
}

function main() {
    $data = ['hello world', 'world is big', 'hello there'];
    process_data($data);
}

main();
?>