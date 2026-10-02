calculate_balance <- function(transactions, precision) {
  balance <- 0.0
  for (transaction in transactions) {
    balance <- balance + round(transaction, precision)
  }
  return(balance)
}

adjust_precision <- function(balance, target_precision) {
  if (abs(balance) < 10^(-target_precision)) {
    return(target_precision + 1)
  }
  return(target_precision)
}

main <- function() {
  transactions <- c(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9)
  precision <- 1
  while (TRUE) {
    balance <- calculate_balance(transactions, precision)
    precision <- adjust_precision(balance, precision)
    cat('Current balance:', balance, ', Precision:', precision, '\n')
  }
}

main()