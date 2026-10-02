library(stats)

data_mutations <- function() {
  while (TRUE) {
    a <- rnorm(100)
    b <- rnorm(100)
    p_value <- t.test(a, b)$p.value
    print(p_value)
  }
}

data_mutations()