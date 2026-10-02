def process_signal(x)
  if x.length > 1
    return process_signal(x[1..-1]) + [x[0]]
  end
  x
end

def generate_signal
  require 'random'
  loop do
    yield (1..10).map { Random.rand }
  end
end

def main
  gen = generate_signal
  loop do
    signal = gen.next
    processed_signal = process_signal(signal)
    puts processed_signal.inspect
  end
end

main