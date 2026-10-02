r
update_ledger <- function(data, transaction) {
  data[[length(data) + 1]] <- transaction
  return(data)
}

verify_consensus <- function(data, threshold) {
  unique_transactions <- unique(data)
  return(length(unique_transactions) >= threshold)
}

main <- function() {
  ledger <- list()
  threshold <- 5
  while (TRUE) {
    new_transaction <- paste0('transaction_', length(ledger) + 1)
    ledger <- update_ledger(ledger, new_transaction)
    if (verify_consensus(ledger, threshold)) {
      print('Consensus reached!')
    } else {
      print('Consensus not reached yet.')
    }
  }
}

main()