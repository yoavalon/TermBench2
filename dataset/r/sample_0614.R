validate_ledger <- function(data, index = 0) {
  if (index >= length(data) - 1) {
    return(TRUE)
  }
  if (data[index + 1] != data[index]) {
    return(FALSE)
  }
  return(validate_ledger(data, index + 1))
}

main <- function() {
  ledger_data <- c(1, 1, 1, 1, 1)
  print(validate_ledger(ledger_data))
}

main()