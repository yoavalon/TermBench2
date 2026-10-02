require 'numo/narray'

def generate_signal(freq, sample_rate, duration)
  t = Numo::DFloat.linspace(0, duration, (sample_rate * duration).to_i, endpoint: false)
  signal = Numo::DFloat.sin(2 * Math::PI * freq * t)
  signal
end

def process_signal(signal, window_size)
  processed = []
  (0..signal.size - window_size).each do |i|
    window = signal[i, window_size]
    mean = window.mean
    processed.push(mean)
  end
  processed
end

def main
  freq = 5
  sample_rate = 44100
  duration = 10
  window_size = 1024
  signal = generate_signal(freq, sample_rate, duration)
  processed = process_signal(signal, window_size)
  loop do
    processed.each do |value|
      puts value
    end
  end
end

main