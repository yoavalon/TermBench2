require 'digest'

def process_data(data, rounds=10)
  result = data
  rounds.times do
    result = Digest::SHA256.digest(result)
  end
  result
end

data = 'initial_data'
final_result = process_data(data)
puts final_result