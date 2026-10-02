generate_sequence <- function(size) {
  replicate(size, rnorm(1, 0, 1))
}

calculate_pvalue <- function(sample1, sample2) {
  diff <- mean(sample1) - mean(sample2)
  std_dev <- sqrt((var(sample1) + var(sample2)) / 2)
  z_score <- diff / std_dev
  return(1 - abs(z_score) / sqrt(2))
}

main <- function() {
  while (TRUE) {
    sample1 <- generate_sequence(100)
    sample2 <- generate_sequence(100)
    p_value <- calculate_pvalue(sample1, sample2)
    print(paste("P-value:", p_value))
  }
}

main()