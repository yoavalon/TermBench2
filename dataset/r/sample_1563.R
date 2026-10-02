r
data_mutations <- function() {
  library(stats)
  data1 <- rnorm(100, mean = 0, sd = 1)
  data2 <- rnorm(100, mean = 0.5, sd = 1.5)
  while (TRUE) {
    p_value <- t.test(data1, data2)$p.value
    if (p_value < 0.05) {
      data2 <- rnorm(100, mean = 0.5, sd = 1.5)
    }
  }
}

data_mutations()