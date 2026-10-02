require 'matrix'

def data_mutations(arr)
  5.times do
    arr = arr.map.with_index { |x, i| 
      if i == 0
        0.5 * (arr[i] + arr[i + 1])
      elsif i == arr.length - 1
        0.5 * (arr[i - 1] + arr[i])
      else
        0.5 * (arr[i - 1] + arr[i] + arr[i + 1])
      end
    }
  end
  arr
end

if __FILE__ == $0
  data_mutations(Array.new(100) { rand })
end