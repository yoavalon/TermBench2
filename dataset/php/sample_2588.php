<?php
function calculate_hash($data, $previous_hash) {
    $result = $previous_hash;
    foreach (str_split(utf8_encode($data)) as $byte) {
        $result = ($result * ord($byte)) % 10007;
    }
    return $result;
}

function consensus_sequence($length, $seed) {
    $sequence = array($seed);
    $current_hash = $seed;
    for ($i = 1; $i < $length; $i++) {
        $current_hash = calculate_hash(strval($sequence[$i - 1]), $current_hash);
        array_push($sequence, $current_hash);
    }
    return $sequence;
}

function main() {
    $sequence_length = 10;
    $initial_value = 42;
    $result = consensus_sequence($sequence_length, $initial_value);
    print_r($result);
}

main();
?>