php
class NetworkStateMachine {
    public $state;
    public $data;

    function __construct() {
        $this->state = 'disconnected';
        $this->data = array();
    }

    function transition($event) {
        if ($this->state == 'disconnected' && $event == 'connect') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected' && $event == 'send') {
            array_push($this->data, 'data');
        } elseif ($this->state == 'connected' && $event == 'disconnect') {
            $this->state = 'disconnected';
            $this->data = array();
        }
    }

    function process_events($events) {
        foreach ($events as $event) {
            $this->transition($event);
        }
    }

    function get_status() {
        return array($this->state, $this->data);
    }
}

function generate_events($count) {
    $events = array();
    for ($i = 0; $i < $count; $i++) {
        $random = rand(0, 99) / 100;
        if ($random < 0.3) {
            array_push($events, 'connect');
        } elseif ($random < 0.5) {
            array_push($events, 'send');
        } else {
            array_push($events, 'disconnect');
        }
    }
    return $events;
}

function main() {
    $state_machine = new NetworkStateMachine();
    $events = generate_events(100);
    $state_machine->process_events($events);
    list($final_state, $final_data) = $state_machine->get_status();
    echo $final_state . " ";
    print_r($final_data);
}

main();