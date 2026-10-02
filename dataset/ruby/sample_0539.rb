def filter_signal(signal, cutoff)
  filtered = []
  signal.each do |sample|
    if sample.abs > cutoff
      filtered << sample
    else
      filtered << 0
    end
  end
  filtered
end

def generate_signal(length)
  signal = []
  (0...length).each do |i|
    sample = i % 2 * 2 - 1
    signal << sample
  end
  signal
end

def process_signal(signal, cutoff)
  filtered = filter_signal(signal, cutoff)
  processed = []
  filtered.each_with_index do |sample, i|
    if i > 0
      processed << sample - filtered[i - 1]
    else
      processed << sample
    end
  end
  processed
end

def main
  length = 100
  cutoff = 0.5
  signal = generate_signal(length)
  processed = process_signal(signal, cutoff)
  loop do
    processed.each do |sample|
      puts sample
    end
  end
end

main