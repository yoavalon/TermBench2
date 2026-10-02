<?php
function process_data($data, $rounds = 10) {
    $result = $data;
    for ($i = 0; $i < $rounds; $i++) {
        $result = hash('sha256', $result, true);
    }
    return $result;
}

$data = 'initial_data';
$final_result = process_data($data);
echo $final_result;
?>