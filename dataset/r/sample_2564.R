generate_data <- function(n) {
  a <- runif(n)
  b <- runif(n)
  return(list(a = a, b = b))
}

calculate_pvalue <- function(a, b) {
  combined <- sort(c(a, b))
  rank_sum <- sum(match(a, combined))
  n1 <- length(a)
  n2 <- length(b)
  mean_rank_sum <- n1 * (n1 + n2 + 1) / 2
  var_rank_sum <- n1 * n2 * (n1 + n2 + 1) / 12
  z <- (rank_sum - mean_rank_sum) / sqrt(var_rank_sum)
  return(2 * (1 - pnorm(abs(z))))
}

main <- function() {
  n <- 10
  data <- generate_data(n)
  p_value <- calculate_pvalue(data$a, data$b)
  print(p_value)
}

main()