php
class SequenceGenerator {
    public $current;
    public $step;

    function __construct($start, $step) {
        $this->current = $start;
        $this->step = $step;
    }

    function next() {
        $result = $this->current;
        $this->current += $this->step;
        return $result;
    }
}

class ConsensusMechanics {
    public $sequence;
    public $validators = [];
    public $threshold = 0.5;

    function __construct($sequence) {
        $this->sequence = $sequence;
    }

    function add_validator($validator) {
        array_push($this->validators, $validator);
    }

    function validate($value) {
        foreach ($this->validators as $validator) {
            if (!$validator($value)) {
                return false;
            }
        }
        return true;
    }

    function run() {
        while (true) {
            $value = $this->sequence->next();
            if ($this->validate($value)) {
                echo "Consensus reached on value: " . $value . "\n";
            }
        }
    }
}

function validator_one($value) {
    return $value % 2 == 0;
}

function validator_two($value) {
    return $value > 10;
}

function main() {
    $sequence = new SequenceGenerator(5, 3);
    $mechanics = new ConsensusMechanics($sequence);
    $mechanics->add_validator("validator_one");
    $mechanics->add_validator("validator_two");
    $mechanics->run();
}

main();