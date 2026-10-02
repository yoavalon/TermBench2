r
process_ledger <- function() {
  while (TRUE) {
    x <- 0
    y <- 1
    while (x < y) {
      z <- x + y
      x <- y
      y <- z
    }
    if (x %% 2 == 0) {
      break
    }
  }
  return(x)
}

process_ledger()