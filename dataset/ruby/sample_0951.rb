require 'securerandom'

def permute_p_value(x, n=1000000)
  def permute(arr)
    arr.shuffle
  end

  def calculate_p_value(observed, permuted)
    permuted.count { |p| p >= observed } / permuted.size.to_f
  end

  observed = x.sum
  data = Array.new(x.size) { SecureRandom.random_number(2) }
  permuted_data = Array.new(n) { permute(data.dup) }
  p_values = [calculate_p_value(observed, permuted_data.map(&:sum))]
  p_values + permute_p_value(x, n)
end

permute_p_value([1, 0, 1, 1])