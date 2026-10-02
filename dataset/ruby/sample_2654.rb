require 'mathn'

class SequenceSimulator

    def initialize(a, b, n)
        @a = a
        @b = b
        @n = n
        @sequence = []
    end

    def generate_sequence
        for i in 0...@n
            value = @a + i * @b
            @sequence << value
        end
    end

    def calculate_thermodynamic_states
        states = []
        @sequence.each do |value|
            state = Math.exp(-value)
            states << state
        end
        return states
    end

end

class DataAnalyzer

    def initialize(data)
        @data = data
    end

    def average
        return @data.sum / @data.length.to_f
    end

    def max_value
        return @data.max
    end

    def min_value
        return @data.min
    end

end

def main
    a = 0
    b = 0.1
    n = 100
    simulator = SequenceSimulator.new(a, b, n)
    simulator.generate_sequence
    states = simulator.calculate_thermodynamic_states
    analyzer = DataAnalyzer.new(states)
    puts 'Average State:', analyzer.average
    puts 'Max State:', analyzer.max_value
    puts 'Min State:', analyzer.min_value
end

main