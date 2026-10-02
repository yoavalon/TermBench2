<?php
function simulate_cipher_sequence($data, $iterations) {
    for ($i = 0; $i < $iterations; $i++) {
        $data = hash('sha256', $data, true);
    }
    return $data;
}

function main() {
    $initial_data = 'hello';
    $iterations = 5;
    $result = simulate_cipher_sequence($initial_data, $iterations);
    echo bin2hex($result);
}

main();
?>