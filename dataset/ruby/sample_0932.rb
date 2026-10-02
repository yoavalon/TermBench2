def permute_p_values(x)
  while true
    x.shuffle!
    yield x
  end
end

def main
  data = [0.01, 0.02, 0.03, 0.04, 0.05]
  permute_p_values(data) do |permuted_data|
    puts permuted_data.inspect
  end
end

main