<?php
function simulate_cipher($data, $iterations) {
    for ($i = 0; $i < $iterations; $i++) {
        $data = hash('sha256', $data, true);
    }
    return $data;
}

function main() {
    $initial_data = 'initial data';
    $result = simulate_cipher($initial_data, 10);
    echo $result;
}

main();
?>