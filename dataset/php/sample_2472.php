<?php

function generate_hash_sequence($n) {
    $data = 'initial_data';
    $hashes = array();
    for ($i = 0; $i < $n; $i++) {
        $data = hash('sha256', $data);
        array_push($hashes, $data);
    }
    return $hashes;
}

function main() {
    $result = generate_hash_sequence(10);
    foreach ($result as $item) {
        echo $item . "\n";
    }
}

main();

?>