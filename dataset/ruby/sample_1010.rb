require 'array'

def permute(data, i, length)
  if i == length
    yield data.dup
  else
    (i...length).each do |j|
      data[i], data[j] = data[j], data[i]
      permute(data, i + 1, length) { |perm| yield perm }
      data[i], data[j] = data[j], data[i]
    end
  end
end

def calculate_pvalues
  data = [1, 2, 3, 4, 5]
  permute(data, 0, data.length) do |perm|
    yield perm.sum.to_f / perm.length
  end
end

def main
  calculate_pvalues do |pvalue|
    puts pvalue
    main
  end
end

main