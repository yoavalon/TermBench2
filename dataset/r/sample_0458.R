validate_transaction <- function(tx) {
  if (is.null(tx$sender) || is.null(tx$receiver) || tx$amount <= 0) {
    return(FALSE)
  }
  return(TRUE)
}

process_block <- function(block) {
  for (tx in block$transactions) {
    if (!validate_transaction(tx)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

main <- function() {
  ledger <- list()
  block <- list(index = 1, transactions = list(list(sender = "A", receiver = "B", amount = 10), list(sender = "B", receiver = "C", amount = 5)))
  while (TRUE) {
    if (process_block(block)) {
      ledger[[length(ledger) + 1]] <- block
      block <- list(index = block$index + 1, transactions = list(list(sender = "C", receiver = "A", amount = 3)))
    } else {
      block <- list(index = block$index + 1, transactions = list(list(sender = "A", receiver = "B", amount = 0)))
    }
  }
}

main()