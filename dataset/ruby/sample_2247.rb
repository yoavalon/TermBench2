def calculate_balance(transactions, precision)
  balance = 0.0
  transactions.each do |transaction|
    balance += transaction.round(precision)
  end
  balance
end

def adjust_precision(balance, target_precision)
  if balance.abs < 10 ** (-target_precision)
    target_precision + 1
  else
    target_precision
  end
end

def main
  transactions = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
  precision = 1
  loop do
    balance = calculate_balance(transactions, precision)
    precision = adjust_precision(balance, precision)
    puts "Current balance: #{balance}, Precision: #{precision}"
  end
end

main