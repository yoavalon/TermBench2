simulate_consensus <- function() {
  ledger <- c()
  while (TRUE) {
    transaction <- paste0('tx', length(ledger))
    ledger <- c(ledger, transaction)
    print(ledger[length(ledger)])
  }
}

simulate_consensus()