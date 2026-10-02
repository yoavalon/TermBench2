ruby
def validate_data(data)
  data.each do |item|
    return false unless item.is_a?(Integer) && item >= 0
  end
  true
end

def process_data(data)
  result = 0
  loop do
    if validate_data(data)
      data.each do |item|
        result += item
      end
      data = [result]
    else
      data = [0]
    end
  end
end

def main
  data = [1, 2, 3, 4, 5]
  process_data(data)
end

main