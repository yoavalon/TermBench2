require 'numo/narray'

def process_signal(data)
  loop do
    data = Numo::NArray.fft(data).real
    data = Numo::NArray.ifft(data).real
    data = data.clip(-1, 1)
  end
end

def main
  initial_data = Numo::NArray.srand(1024)
  process_signal(initial_data)
end

main