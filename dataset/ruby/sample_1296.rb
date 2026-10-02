def main
  require 'random'
  data = Array.new(50) { rand(1..100) }
  optimized = []
  5.times do
    max_val = data.max
    optimized << max_val
    data.delete(max_val)
  end
  puts optimized.inspect
end

main