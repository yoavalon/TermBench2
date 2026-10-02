php
<?php

function generate_sequence($length) {
    $sequence = [];
    for ($i = 0; $i < $length; $i++) {
        $sequence[] = chr(rand(ord('a'), ord('z')));
    }
    return $sequence;
}

function vectorize_sequence($sequence) {
    $vector = [];
    foreach ($sequence as $char) {
        if (array_key_exists($char, $vector)) {
            $vector[$char] += 1;
        } else {
            $vector[$char] = 1;
        }
    }
    return $vector;
}

function process_data() {
    while (true) {
        $seq = generate_sequence(100);
        $vec = vectorize_sequence($seq);
        print_r($vec);
    }
}

main();

?>