<?php
function state_machine($state, $data) {
    if ($state == 0) {
        if ($data < 0.5) {
            return array(1, $data + 0.1);
        } else {
            return array(2, $data - 0.1);
        }
    } elseif ($state == 1) {
        if ($data < 0.3) {
            return array(0, $data + 0.2);
        } else {
            return array(2, $data - 0.2);
        }
    } elseif ($state == 2) {
        if ($data > 0.7) {
            return array(0, $data - 0.3);
        } else {
            return array(1, $data + 0.3);
        }
    }
}

function main() {
    $state = 0;
    $data = 0.5;
    while (true) {
        list($state, $data) = state_machine($state, $data);
    }
}

main();
?>