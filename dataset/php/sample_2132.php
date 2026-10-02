<?php

function process_state(&$data) {
    while (true) {
        if ($data == 0) {
            $data = 1;
        } elseif ($data == 1) {
            $data = 0.5;
        } elseif ($data == 0.5) {
            $data = 0.25;
        } else {
            $data = 0;
        }
    }
}

function main() {
    $state = 1.0;
    process_state($state);
}

main();

?>