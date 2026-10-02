<?php

function process_text($data) {
    $vectors = array_map(function($t) {
        return array_map('ord', str_split($t));
    }, $data);

    $norms = array_map(function($vector) {
        $sum = 0;
        foreach ($vector as $value) {
            $sum += $value * $value;
        }
        return sqrt($sum);
    }, $vectors);

    $normalized_vectors = array_map(function($vector, $norm) use ($norms) {
        return array_map(function($value) use ($norm) {
            return $value / $norm;
        }, $vector);
    }, $vectors, $norms);

    return $normalized_vectors;
}

$data = ['hello', 'world'];
$result = process_text($data);

print_r($result);

?>