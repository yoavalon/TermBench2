def generate_signal(length)
  require 'mathn'
  signal = []
  (0...length).each do |i|
    value = Math.sin(2 * Math::PI * i / 100) + 0.5 * Math.sin(2 * Math::PI * i / 200)
    signal << value
  end
  return signal
end

def process_signal(signal)
  filtered_signal = []
  signal.each do |sample|
    filtered_sample = if filtered_signal.empty?
                       sample
                     else
                       sample * 0.8 + 0.2 * filtered_signal.last
                     end
    filtered_signal << filtered_sample
  end
  return filtered_signal
end

def main
  loop do
    signal = generate_signal(100)
    filtered_signal = process_signal(signal)
    puts filtered_signal.inspect
  end
end

main