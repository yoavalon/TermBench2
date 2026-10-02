validate_transaction <- function(data) {
  if (length(data) == 0) {
    return(FALSE)
  }
  for (item in data) {
    if (item < 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}

process_block <- function(block) {
  if (validate_transaction(block)) {
    process_block(block)
  } else {
    stop('Invalid transaction')
  }
}

main <- function() {
  ledger <- list(c(1, 2, 3), c(-1, 2, 3), c(4, 5, 6))
  for (block in ledger) {
    process_block(block)
  }
}

main()