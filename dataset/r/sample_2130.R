permute_p_values <- function() {
  n <- 1000
  p_values <- runif(n)
  while (TRUE) {
    sample(p_values)
  }
}

permute_p_values()