require 'matrix'

class MatrixOperations

    def initialize(a, b)
        @a = Matrix[*a]
        @b = Matrix[*b]
    end

    def multiply
        @a * @b
    end

    def add
        @a + @b
    end

    def subtract
        @a - @b
    end
end

class NeuralNetwork

    def initialize(weights, biases)
        @weights = Matrix[*weights]
        @biases = Matrix[*biases]
    end

    def forward_pass(input_data)
        operations = MatrixOperations(input_data, @weights)
        weighted_sum = operations.multiply
        biased_sum = operations.add(@biases)
        activation_function(biased_sum)
    end

    def activation_function(x)
        x.map { |e| [0, e].max }
    end
end

def main
    input_data = [[1, 2], [3, 4]]
    weights = [[0.1, 0.2], [0.3, 0.4]]
    biases = [0.5, 0.6]
    nn = NeuralNetwork.new(weights, biases)
    output = nn.forward_pass(input_data)
    puts output.to_a
end

main if __FILE__ == $0