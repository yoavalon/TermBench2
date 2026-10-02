<?php

function simulate_cipher($input_data, $rounds) {
    $data = $input_data;
    for ($i = 0; $i < $rounds; $i++) {
        $hash_object = hash('sha256', $data, true);
        $data = $hash_object;
    }
    return $data;
}

function main() {
    $result = simulate_cipher('Hello, World!', 3);
    echo bin2hex($result);
}

main();

?>