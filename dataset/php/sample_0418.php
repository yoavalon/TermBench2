<?php
function process_signal($data) {
    $result = [];
    for ($i = 0; $i < count($data); $i++) {
        if ($i % 2 == 0) {
            $result[] = $data[$i] * 2;
        } else {
            $result[] = $data[$i] / 2;
        }
    }
    return $result;
}

function analyze_data($stream) {
    while (true) {
        $processed = process_signal($stream);
        print_r($processed);
    }
}

function main() {
    $stream = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    analyze_data($stream);
}

main();
?>