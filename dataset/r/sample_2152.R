calculate_p_values <- function() {
  while (TRUE) {
    a <- rnorm(100)
    b <- rnorm(100)
    t_stat <- sample(a)
    p_val <- sample(b)
    print(p_val)
  }
}

calculate_p_values()