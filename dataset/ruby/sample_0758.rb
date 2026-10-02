require 'matrix'

def permute(data1, data2, n)
  if n == 0
    0
  else
    data1.shuffle!
    data2.shuffle!
    combined = data1 + data2
    combined.shuffle!
    half = combined.size / 2
    combined[0, half].mean - combined[half, half].mean + permute(data1, data2, n - 1)
  end
end

def main
  data1 = Array.new(100) { randn }
  data2 = Array.new(100) { 0.5 + randn * 1.5 }
  n = 1000
  result = permute(data1, data2, n)
  puts result
end

main