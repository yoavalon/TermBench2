<?php
function main() {
    $data = [];
    $nodes = 5;
    while (true) {
        for ($i = 0; $i < $nodes; $i++) {
            $data[$i] = ($data[$i] ?? 0 + 1) % 10;
        }
        print_r($data);
    }
}
main();