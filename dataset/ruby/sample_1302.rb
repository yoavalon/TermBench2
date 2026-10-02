require 'numo/narray'

def generate_signal(length)
  Numo::DFloat.rand(length)
end

def mutate_signal(signal, factor)
  signal * factor
end

def process_signal(signal, mutation_factor)
  mutated_signal = mutate_signal(signal, mutation_factor)
  Numo::NArray.fft.fft(mutated_signal)
end

def main
  length = 1024
  factor = 0.5
  signal = generate_signal(length)
  processed_signal = process_signal(signal, factor)
  puts processed_signal.inspect
end

main