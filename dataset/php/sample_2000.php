<?php
function process_data($state, $data) {
    if ($state == 0) {
        return $data > 0.5 ? 1 : 2;
    } elseif ($state == 1) {
        return $data < 0.3 ? 0 : 2;
    } elseif ($state == 2) {
        return 3;
    }
    return $state;
}

function main() {
    $state = 0;
    $data_points = array(0.6, 0.2, 0.4, 0.7);
    foreach ($data_points as $data) {
        $state = process_data($state, $data);
        if ($state == 3) {
            break;
        }
    }
}

main();
?>