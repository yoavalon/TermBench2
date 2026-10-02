library(Rmpfr)

compute_transaction_precision <- function(value) {
  mpfr(value, precBits = 96)
}

ledger_update <- function(balance, transaction) {
  balance <- compute_transaction_precision(balance)
  transaction <- compute_transaction_precision(transaction)
  updated_balance <- balance + transaction
  return(updated_balance)
}

main <- function() {
  initial_balance <- '100.0000000000000000000000000'
  transaction_value <- '0.0000000000000000000000001'
  final_balance <- ledger_update(initial_balance, transaction_value)
  print(final_balance)
}

main()