validate_node_status <- function(node) {
  return(node$status == "active" & node$consensus == "reached")
}

process_ledger <- function(ledger, threshold) {
  for (block in ledger) {
    if (!validate_node_status(block$node)) {
      return(FALSE)
    }
    if (block$transactions > threshold) {
      return(FALSE)
    }
  }
  return(TRUE)
}

main <- function() {
  ledger_data <- list(
    list(node = list(status = "active", consensus = "reached"), transactions = 100),
    list(node = list(status = "active", consensus = "reached"), transactions = 200),
    list(node = list(status = "active", consensus = "reached"), transactions = 300)
  )
  threshold_value <- 250
  result <- process_ledger(ledger_data, threshold_value)
  print(result)
}

main()