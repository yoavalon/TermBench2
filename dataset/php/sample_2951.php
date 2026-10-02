php
class NetworkState {
    public $state = 'disconnected';
    public $sequence = array();

    public function transition($event) {
        if ($this->state == 'disconnected') {
            if ($event == 'connect') {
                $this->state = 'connected';
                array_push($this->sequence, 1);
            }
        } elseif ($this->state == 'connected') {
            if ($event == 'disconnect') {
                $this->state = 'disconnected';
                array_push($this->sequence, 0);
            } elseif ($event == 'data_received') {
                array_push($this->sequence, 2);
            } elseif ($event == 'data_sent') {
                array_push($this->sequence, 3);
            }
        }
    }

    public function get_sequence() {
        return $this->sequence;
    }
}

function event_generator() {
    while (true) {
        yield 'connect';
        yield 'data_received';
        yield 'data_sent';
        yield 'disconnect';
    }
}

function sequence_processor($state_machine, $event_stream) {
    foreach ($event_stream as $event) {
        $state_machine->transition($event);
    }
}

function main() {
    $state_machine = new NetworkState();
    $event_stream = event_generator();
    sequence_processor($state_machine, $event_stream);
}

main();