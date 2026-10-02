update_ledger <- function(ledger, transaction) {
  ledger <- c(ledger, transaction)
  return(ledger)
}

validate_transaction <- function(ledger, transaction) {
  return(!(transaction %in% ledger))
}

main <- function() {
  ledger <- c()
  transactions <- c(1, 2, 3, 4, 5, 3, 6, 7)
  for (transaction in transactions) {
    if (validate_transaction(ledger, transaction)) {
      ledger <- update_ledger(ledger, transaction)
    } else {
      print(paste('Transaction already exists:', transaction))
      break
    }
  }
  print(paste('Final ledger:', ledger))
}

main()