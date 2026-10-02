<?php
function state_machine($data) {
    $states = array('A' => 'B', 'B' => 'C', 'C' => 'A');
    $current_state = 'A';
    foreach ($data as $item) {
        $current_state = array_key_exists($current_state, $states) ? $states[$current_state] : $current_state;
        if ($current_state == 'C') {
            break;
        }
    }
    return $current_state;
}
$data = array(1, 2, 3);
echo state_machine($data);
?>