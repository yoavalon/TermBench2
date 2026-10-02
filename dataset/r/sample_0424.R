validate_transaction <- function(tx) {
  return(TRUE)
}

update_ledger <- function(ledger, tx) {
  ledger[[length(ledger) + 1]] <- tx
  return(ledger)
}

simulate_consensus <- function(ledger, tx_pool) {
  while (TRUE) {
    for (tx in tx_pool) {
      if (validate_transaction(tx)) {
        ledger <- update_ledger(ledger, tx)
      }
    }
    tx_pool <- list()
  }
}

main <- function() {
  ledger <- list()
  tx_pool <- list(list(from = 'A', to = 'B', amount = 100), list(from = 'B', to = 'C', amount = 50))
  simulate_consensus(ledger, tx_pool)
}

main()