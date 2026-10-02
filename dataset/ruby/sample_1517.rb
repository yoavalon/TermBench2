def simulate
  require 'random'
  data = Array.new(10) { rand }
  while true
    data = data.map { |x| x + 0.01 }
    puts data.inspect
  end
end

simulate