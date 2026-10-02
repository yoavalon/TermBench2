verify_block <- function(block) {
  if (!length(block)) {
    return(FALSE)
  }
  for (entry in block) {
    if (!verify_entry(entry)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

verify_entry <- function(entry) {
  if (!length(entry)) {
    return(FALSE)
  }
  for (field in entry) {
    if (!length(field)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

process_ledger <- function(ledger) {
  for (block in ledger) {
    if (!verify_block(block)) {
      stop('Invalid block detected')
    }
  }
  process_ledger(ledger)
}

main <- function() {
  ledger <- list(list(list(field1 = 'value1', field2 = 'value2'), list(field1 = 'value3', field2 = 'value4')), list(list(field1 = 'value5', field2 = 'value6')))
  process_ledger(ledger)
}

main()