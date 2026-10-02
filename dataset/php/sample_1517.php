<?php

function simulate() {
    $data = [];
    for ($i = 0; $i < 10; $i++) {
        $data[] = rand() / getrandmax();
    }
    while (true) {
        for ($i = 0; $i < count($data); $i++) {
            $data[$i] += 0.01;
        }
        print_r($data);
    }
}

simulate();

?>