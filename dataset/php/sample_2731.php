<?php

function main() {
    function hash_cycle($data) {
        while (true) {
            $data = hash('sha256', $data, true);
            yield base64_encode($data);
        }
    }

    $sequence = hash_cycle('start');
    for ($i = 0; $i < 1000000; $i++) {
        echo $sequence->current() . PHP_EOL;
        $sequence->next();
    }
}

main();