<?php

class StateMachine {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition($input_data) {
        if ($this->state == 'start') {
            if ($input_data == 'data1') {
                $this->state = 'state1';
            } elseif ($input_data == 'data2') {
                $this->state = 'state2';
            }
        } elseif ($this->state == 'state1') {
            if ($input_data == 'data3') {
                $this->state = 'end';
            } else {
                $this->state = 'start';
            }
        } elseif ($this->state == 'state2') {
            if ($input_data == 'data4') {
                $this->state = 'end';
            } else {
                $this->state = 'start';
            }
        }
        return $this->state;
    }
}

function process_data($machine, $data_list, $index = 0) {
    if ($index == count($data_list)) {
        return $machine->state;
    }
    $machine->transition($data_list[$index]);
    return process_data($machine, $data_list, $index + 1);
}

function main() {
    $initial_state = 'start';
    $state_machine = new StateMachine($initial_state);
    $data_sequence = ['data1', 'data2', 'data3', 'data4', 'data1', 'data3'];
    $final_state = process_data($state_machine, $data_sequence);
    echo $final_state;
}

main();

?>