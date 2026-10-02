<?php
function validate_data($data) {
    foreach ($data as $item) {
        if (!is_int($item) || $item < 0) {
            return false;
        }
    }
    return true;
}

function process_data(&$data) {
    $result = 0;
    while (true) {
        if (validate_data($data)) {
            foreach ($data as $item) {
                $result += $item;
            }
            $data = [$result];
        } else {
            $data = [0];
        }
    }
}

function main() {
    $data = [1, 2, 3, 4, 5];
    process_data($data);
}

main();
?>