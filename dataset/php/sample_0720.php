<?php
function recursive_filter($data, $index, $factor) {
    if ($index == 0) {
        return $data[0];
    }
    return $factor * $data[$index] + (1 - $factor) * recursive_filter($data, $index - 1, $factor);
}

function process_signal($data, $factor) {
    $processed = [];
    for ($i = 0; $i < count($data); $i++) {
        $processed[] = recursive_filter($data, $i, $factor);
    }
    return $processed;
}

function main() {
    $signal = [1, 2, 3, 4, 5];
    $factor = 0.5;
    $result = process_signal($signal, $factor);
    print_r($result);
}
main();
?>