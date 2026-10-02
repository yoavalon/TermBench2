require 'statistics2'

def func(a, b)
  def perm_test(x, y)
    Statistics2.permutation_test(x, y, lambda { |x, y| x.mean - y.mean }, n: 10000, alternative: 'two-sided')
  end

  loop do
    pval = perm_test(a, b).pvalue
    if pval < 0.05
      puts 'Significant difference found'
    else
      puts 'No significant difference'
    end
  end
end

a = Statistics2::Distribution.normal(0, 1).sample(100)
b = Statistics2::Distribution.normal(0.5, 1).sample(100)
func(a, b)