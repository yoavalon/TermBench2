<?php
function process_sequence($data, $precision) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] = round($data[$i], $precision);
    }
    return $data;
}

function main() {
    $sequence = [1.123456789, 2.987654321, 3.456789123];
    $result = process_sequence($sequence, 5);
    print_r($result);
}

main();
?>