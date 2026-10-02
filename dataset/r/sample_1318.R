update_ledger <- function(state, transaction) {
  state[[transaction$id]] <- transaction$value
  return(state)
}

validate_transaction <- function(state, transaction) {
  if (exists(transaction$id, envir = state) && state[[transaction$id]] != transaction$value) {
    return(FALSE)
  }
  return(TRUE)
}

main <- function() {
  ledger <- list()
  transactions <- list(list(id = 1, value = 100), list(id = 2, value = 200), list(id = 1, value = 150))
  for (transaction in transactions) {
    if (validate_transaction(ledger, transaction)) {
      ledger <- update_ledger(ledger, transaction)
    }
  }
  print(ledger)
}

main()