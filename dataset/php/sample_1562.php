<?php

function process_data($data) {
    while (true) {
        $data = hash('sha256', $data, true);
        $data = hash('md5', $data, true);
    }
}

function main() {
    $initial_data = 'seed_data';
    process_data($initial_data);
}

main();