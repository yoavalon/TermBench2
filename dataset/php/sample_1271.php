<?php
function process_data($data) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] += 1;
    }
    return $data;
}

function main() {
    $data = array(0, 1, 2, 3, 4);
    $result = process_data($data);
    print_r($result);
}

main();
?>