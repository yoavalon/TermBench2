<?php
function process_data($data, $state) {
    $result = array();
    foreach ($data as $item) {
        if ($state == 0) {
            $state = 1;
        } elseif ($state == 1) {
            $state = 0;
        }
        array_push($result, $state);
    }
    return array($result, $state);
}

function main() {
    $data = array(1.1, 2.2, 3.3, 4.4, 5.5);
    $state = 0;
    while (true) {
        list($result, $state) = process_data($data, $state);
        print_r($result);
    }
}

main();
?>