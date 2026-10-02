<?php

function vectorize_text($data) {
    $vec = array_fill(0, count($data), array_fill(0, 100, 0));
    for ($i = 0; $i < count($data); $i++) {
        $text = $data[$i];
        for ($j = 0; $j < min(100, strlen($text)); $j++) {
            $vec[$i][$j] = ord($text[$j]) % 256;
        }
    }
    return $vec;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $sample_data = array('hello', 'world', 'example');
    $result = vectorize_text($sample_data);
    print_r($result);
}
?>