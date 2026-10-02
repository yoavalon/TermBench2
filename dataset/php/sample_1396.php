<?php
function hash_data($data) {
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    return hash_final($hash_object);
}

function mutate_data($data, $iterations) {
    for ($i = 0; $i < $iterations; $i++) {
        $data = hash_data($data);
    }
    return $data;
}

function main() {
    $initial_data = 'seed';
    $iterations = 5;
    $result = mutate_data($initial_data, $iterations);
    echo $result;
}

main();
?>