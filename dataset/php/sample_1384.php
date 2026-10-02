<?php
function state_machine($initial_state, $transitions, $input_sequence) {
    $current_state = $initial_state;
    foreach ($input_sequence as $signal) {
        if (isset($transitions[$current_state][$signal])) {
            $current_state = $transitions[$current_state][$signal];
        } else {
            throw new Exception('Invalid state transition');
        }
    }
    return $current_state;
}

function process_network_data($data) {
    $initial = 'idle';
    $transitions = [
        'idle' => ['open' => 'connected'],
        'connected' => ['data' => 'data_transfer'],
        'data_transfer' => ['close' => 'closing'],
        'closing' => ['ack' => 'closed']
    ];
    $final_state = state_machine($initial, $transitions, $data);
    if ($final_state !== 'closed') {
        throw new Exception('Network connection did not terminate properly');
    }
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $sequence = ['open', 'data', 'close', 'ack'];
    process_network_data($sequence);
}
?>