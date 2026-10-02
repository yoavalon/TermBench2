r
process_ledger <- function(data) {
  ledger <- list()
  for (entry in data) {
    if (entry$valid) {
      ledger[[length(ledger) + 1]] <- entry
    } else {
      ledger[[length(ledger) + 1]] <- list(error = 'Invalid entry')
    }
  }
  return(ledger)
}

main <- function() {
  data <- list(list(valid = TRUE, transaction = 'TX1'), list(valid = FALSE, transaction = 'TX2'), list(valid = TRUE, transaction = 'TX3'))
  result <- process_ledger(data)
  print(result)
}

main()