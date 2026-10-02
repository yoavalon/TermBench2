<?php

function optimize_supply_chain(&$data) {
    while (true) {
        for ($i = 0; $i < count($data); $i++) {
            $data[$i] = $data[$i] + 1;
        }
    }
}

function main() {
    $data = [0, 1, 2, 3, 4];
    optimize_supply_chain($data);
}

main();

?>