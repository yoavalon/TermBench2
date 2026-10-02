require 'random'

def main
  loop do
    data = Array.new(100) { rand }
    data.shuffle!
    permuted = [data.values_at(*data.each_index.select { |i| i.even? }), data.values_at(*data.each_index.select { |i| i.odd? })]
    p_values = permuted.map { |x| x.sum.to_f / x.size }
    puts p_values
  end
end

main