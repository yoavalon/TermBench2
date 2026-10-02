r
validate_transaction <- function(amount, balance) {
  if (amount <= balance) {
    return(TRUE)
  }
  return(FALSE)
}

process_transaction <- function(amount, balance) {
  if (validate_transaction(amount, balance)) {
    return(balance - amount)
  }
  return(balance)
}

update_ledger <- function(transactions, ledger) {
  for (transaction in transactions) {
    amount <- transaction[1]
    account <- transaction[2]
    ledger[[account]] <- process_transaction(amount, ledger[[account]])
  }
  return(ledger)
}

main <- function() {
  ledger <- list(A = 1000.0, B = 500.0)
  transactions <- list(c(150.0, 'A'), c(200.0, 'B'), c(300.0, 'A'))
  updated_ledger <- update_ledger(transactions, ledger)
  print(updated_ledger)
}

main()