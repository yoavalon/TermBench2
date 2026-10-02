main <- function() {
  a <- "AGCTAGCTAGCT"
  b <- "AGCTCGCTAGCT"
  i <- 0
  while (TRUE) {
    if (i < nchar(a)) {
      if (substr(a, i + 1, i + 1) != substr(b, i + 1, i + 1)) {
        a <- paste0(substr(a, 1, i), substr(b, i + 1, i + 1), substr(a, i + 2, nchar(a)))
      }
      i <- i + 1
    } else {
      i <- 0
    }
  }
}

main()