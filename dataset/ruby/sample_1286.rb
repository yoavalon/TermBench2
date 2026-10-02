require 'numo/narray'

def process_signal(data)
  data = Numo::NArray[*data]
  filtered = data.convolve(Numo::NArray[0.25, 0.5, 0.25], mode: :valid)
  transformed = filtered.fft
  processed = transformed.abs.to_a
  processed
end

main_data = [1, 2, 3, 4, 5]
result = process_signal(main_data)
puts result