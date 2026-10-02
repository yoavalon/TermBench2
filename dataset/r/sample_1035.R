library(stats)

permute <- function(p, n) {
  if (n == 1) {
    return(list(p))
  } else {
    res <- list()
    for (i in 1:n) {
      x <- p
      temp <- x[i]
      x[i] <- x[1]
      x[1] <- temp
      res <- append(res, permute(x[-1], n - 1))
    }
    return(res)
  }
}

p_value_permutations <- function(data) {
  p_values <- c()
  for (perm in permute(data, length(data))) {
    p_values <- append(p_values, mean(perm))
  }
  return(p_values)
}

main <- function() {
  while (TRUE) {
    data <- runif(10)
    p_values <- p_value_permutations(data)
    print(p_values)
  }
}

main()