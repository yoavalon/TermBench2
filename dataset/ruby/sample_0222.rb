require 'matrix'

class MatrixOps

    def initialize(data)
        @data = Matrix[*data]
    end

    def forward_pass(weights)
        @data * Matrix[*weights]
    end

end

class Network

    def initialize(layers)
        @layers = layers
    end

    def compute(input_data)
        @layers.each do |layer|
            input_data = layer.forward_pass(input_data.to_a)
        end
        input_data
    end

end

class BoundaryConditions

    def initialize(network)
        @network = network
    end

    def validate(input_data, expected_output)
        output = @network.compute(input_data)
        (output.to_a - expected_output).flatten.all? { |x| x.abs < 1e-10 }
    end

end

def main
    data = [[1, 2], [3, 4]]
    weights1 = [[0.1, 0.2], [0.3, 0.4]]
    weights2 = [[0.5, 0.6], [0.7, 0.8]]
    layer1 = MatrixOps.new(data)
    layer2 = MatrixOps.new(weights1)
    layer3 = MatrixOps.new(weights2)
    network = Network.new([layer1, layer2, layer3])
    boundary_conditions = BoundaryConditions.new(network)
    input_data = [[1, 1]]
    expected_output = [[0.7, 0.8]]
    result = boundary_conditions.validate(input_data, expected_output)
    puts result
end

main if __FILE__ == $0