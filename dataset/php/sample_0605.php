<?php
function process_signal($data, $index = 0) {
    if ($index >= count($data)) {
        return [];
    }
    $processed = $data[$index] * 2;
    return [$processed] + process_signal($data, $index + 1);
}

function main() {
    $signal = [1, 2, 3, 4, 5];
    $result = process_signal($signal);
    print_r($result);
}

main();
?>