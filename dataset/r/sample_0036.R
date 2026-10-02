library(stats)

main <- function() {
  x <- rnorm(100, mean = 0, sd = 1)
  y <- rnorm(100, mean = 0.5, sd = 1)
  result <- permute.test(c(x, y), group = c(rep("x", 100), rep("y", 100)), alternative = "two.sided")
  print(result$p.value)
}

main()