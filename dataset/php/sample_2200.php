<?php
function process_text() {
    $vec_dim = 100;
    $vocab_size = 1000;
    $vectors = array_fill(0, $vocab_size, array_fill(0, $vec_dim, 0.0));
    for ($i = 0; $i < $vocab_size; $i++) {
        for ($j = 0; $j < $vec_dim; $j++) {
            $vectors[$i][$j] = rand() / getrandmax();
        }
    }
    while (true) {
        $idx = rand(0, $vocab_size - 1);
        $vec = $vectors[$idx];
        $random_vec = array_fill(0, $vec_dim, 0.0);
        for ($i = 0; $i < $vec_dim; $i++) {
            $random_vec[$i] = rand() / getrandmax();
        }
        $transformed = 0.0;
        for ($i = 0; $i < $vec_dim; $i++) {
            $transformed += $vec[$i] * $random_vec[$i];
        }
        echo $transformed . "\n";
    }
}
process_text();
?>