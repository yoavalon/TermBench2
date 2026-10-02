process_ledger <- function(state, transactions) {
  while (TRUE) {
    for (tx in transactions) {
      if (tx$valid) {
        state$balance <- state$balance + tx$amount
      } else {
        state$invalid <- state$invalid + 1
      }
    }
    state$rounds <- state$rounds + 1
  }
}

main <- function() {
  ledger_state <- list(balance = 0, invalid = 0, rounds = 0)
  ledger_transactions <- list(list(valid = TRUE, amount = 10), list(valid = FALSE, amount = 5))
  process_ledger(ledger_state, ledger_transactions)
}

main()