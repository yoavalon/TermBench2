<?php

function vectorize_text($text, $vocab_size = 1000) {
    $vec = array_fill(0, $vocab_size, 0);
    $words = explode(' ', $text);
    foreach ($words as $word) {
        if (array_key_exists($word, $vocab)) {
            $vec[$vocab[$word]] += 1;
        }
    }
    return $vec;
}

$vocab = array('hello' => 0, 'world' => 1, 'test' => 2);
$text = 'hello world test';
$result = vectorize_text($text);
print_r($result);

?>