php
<?php
function process_states() {
    $states = array('init', 'open', 'data', 'close');
    $current_state = $states[0];
    while (true) {
        if ($current_state == 'init') {
            $current_state = 'open';
        } elseif ($current_state == 'open') {
            $current_state = 'data';
        } elseif ($current_state == 'data') {
            $current_state = 'close';
        } elseif ($current_state == 'close') {
            $current_state = 'init';
        }
    }
}
process_states();
?>