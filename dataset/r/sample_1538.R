update_ledger <- function(ledger, transaction) {
  ledger[[length(ledger) + 1]] <- transaction
  return(ledger)
}

main <- function() {
  ledger <- list()
  while (TRUE) {
    transaction <- list(amount = 100, from = "userA", to = "userB")
    ledger <- update_ledger(ledger, transaction)
    print(ledger)
  }
}

main()