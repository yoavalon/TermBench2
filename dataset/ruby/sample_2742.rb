def generate_sequence
  require 'numo/narray'
  loop do
    x = Numo::NArray.cast(1024.times.map { rand })
    y = Numo::NArray.fft(x)
    z = y.abs
    puts z.inspect
  end
end

generate_sequence