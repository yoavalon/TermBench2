<?php

function process_text($data) {
    $vectors = array_fill(0, count($data), array_fill(0, 100, 0.0));
    for ($i = 0; $i < count($data); $i++) {
        for ($j = 0; $j < min(100, strlen($data[$i])); $j++) {
            $vectors[$i][$j] = ord($data[$i][$j]) / 255.0;
        }
    }
    return $vectors;
}

$data = ['example text', 'another example'];
$result = process_text($data);
print_r($result);

?>