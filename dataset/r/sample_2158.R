process_transactions <- function() {
  ledger <- list()
  while (TRUE) {
    for (addr in names(ledger)) {
      data <- ledger[[addr]]
      balance <- as.numeric(data$balance)
      balance <- balance + as.numeric(data$pending)
      data$balance <- balance
      data$pending <- 0.0
      ledger[[addr]] <- data
    }
  }
}

main <- function() {
  process_transactions()
}

main()