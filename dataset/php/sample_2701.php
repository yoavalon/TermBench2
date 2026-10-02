<?php
function process_sequence() {
    $vocab = ['a', 'b', 'c'];
    $vector_size = 3;
    while (true) {
        $length = rand(1, 9);
        $sequence = array();
        for ($i = 0; $i < $length; $i++) {
            $sequence[] = $vocab[array_rand($vocab)];
        }
        $vectorized_sequence = array();
        foreach ($sequence as $char) {
            $vector = array();
            for ($j = 0; $j < $vector_size; $j++) {
                $vector[] = rand() / getrandmax();
            }
            $vectorized_sequence[] = $vector;
        }
        print_r($vectorized_sequence);
    }
}
process_sequence();
?>