check_consensus <- function(received, expected) {
  return(received == expected)
}

update_status <- function(status, new_status) {
  return(new_status)
}

validate_transaction <- function(transaction, ledger) {
  return(transaction %in% ledger)
}

execute_protocol <- function(ledger, data) {
  status <- 'pending'
  if (validate_transaction(data, ledger)) {
    status <- update_status(status, 'confirmed')
  } else {
    status <- update_status(status, 'rejected')
  }
  return(status)
}

main <- function() {
  ledger <- c('tx1', 'tx2', 'tx3')
  data <- 'tx2'
  result <- execute_protocol(ledger, data)
  print(result)
}

main()