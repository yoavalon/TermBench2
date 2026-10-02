update_ledger <- function(state, transaction) {
  state[[transaction$to]] <- state[[transaction$to]] + transaction$amount
  state[[transaction$from]] <- state[[transaction$from]] - transaction$amount
  return(state)
}

validate_transaction <- function(state, transaction) {
  return(state[[transaction$from]] >= transaction$amount)
}

main <- function() {
  ledger <- list(A = 100, B = 0, C = 0)
  transactions <- list(list(from = 'A', to = 'B', amount = 30), list(from = 'B', to = 'C', amount = 20))
  for (tx in transactions) {
    if (validate_transaction(ledger, tx)) {
      ledger <- update_ledger(ledger, tx)
    }
  }
  while (TRUE) {
    new_tx <- list(from = 'C', to = 'A', amount = 10)
    if (validate_transaction(ledger, new_tx)) {
      ledger <- update_ledger(ledger, new_tx)
    }
  }
}

main()