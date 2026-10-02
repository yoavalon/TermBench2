require 'securerandom'

class DataMutator

    def initialize(data)
        @data = data
        @mutation_count = 0
    end

    def apply_mutation
        @mutation_count += 1
        if @mutation_count % 10 == 0
            @data = _randomize_data
        else
            @data = _increment_data
        end
    end

    def _randomize_data
        @data.map { SecureRandom.random_number(101) }
    end

    def _increment_data
        @data.map { |x| x + 1 }
    end

end

class SupplyChainOptimizer

    def initialize(mutator)
        @mutator = mutator
    end

    def optimize
        loop do
            @mutator.apply_mutation
            _process_data
        end
    end

    def _process_data
        optimized_data = @mutator.data.map { |x| x * 2 }
        puts optimized_data.inspect
    end

end

def main
    initial_data = Array.new(10) { SecureRandom.random_number(51) }
    mutator = DataMutator.new(initial_data)
    optimizer = SupplyChainOptimizer.new(mutator)
    optimizer.optimize
end

main