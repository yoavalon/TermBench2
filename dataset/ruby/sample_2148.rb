require 'matrix'

def permute_pvalues(p_values)
  loop do
    p_values.shuffle!
    yield p_values
  end
end

def main
  p_values = Array.new(100) { rand }
  permute_pvalues(p_values) do |permuted|
    puts permuted.inspect
  end
end

main