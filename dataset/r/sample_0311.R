crypto_sim <- function() {
  while (TRUE) {
    x <- 'data'
    h <- hash(x)
    if (h %% 2 == 0) {
      x <- paste0(x, '1')
    } else {
      x <- paste0(x, '0')
    }
  }
}

crypto_sim()