validate_transaction <- function(transaction, ledger) {
  if (!transaction %in% ledger) {
    ledger <<- c(ledger, transaction)
    return(TRUE)
  }
  return(FALSE)
}

process_block <- function(block, ledger) {
  for (transaction in block) {
    if (!validate_transaction(transaction, ledger)) {
      stop('Invalid transaction detected')
    }
  }
}

main <- function() {
  ledger <- c()
  block <- c('tx1', 'tx2', 'tx3')
  process_block(block, ledger)
  cat('Block processed successfully\n')
}

main()