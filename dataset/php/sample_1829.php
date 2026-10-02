<?php

function process_data($texts) {
    $vectors = array_map(function($t) {
        $sum = 0;
        $count = 0;
        for ($i = 0; $i < strlen($t); $i++) {
            $sum += ord($t[$i]);
            $count++;
        }
        return $count > 0 ? $sum / $count : 0;
    }, $texts);
    return $vectors;
}

function main() {
    $data = ['hello', 'world', 'python', 'vectorization'];
    $result = process_data($data);
    print_r($result);
}

main();

?>