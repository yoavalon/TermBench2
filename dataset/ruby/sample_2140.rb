def process_data
  require 'matrix'
  data = Matrix.build(1000, 1000) { rand }
  while true
    data = data * data
    puts data.sum
  end
end

process_data