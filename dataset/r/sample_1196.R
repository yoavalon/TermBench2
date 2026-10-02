library(stats)

permute <- function(data) {
  n <- length(data)
  indices <- sample(1:n, n, replace = FALSE)
  permuted_data <- data[indices]
  return(permuted_data)
}

calculate_pvalue <- function(sample1, sample2) {
  combined <- c(sample1, sample2)
  observed_diff <- mean(sample1) - mean(sample2)
  pvalue <- 1.0
  for (i in 1:10000) {
    permuted <- permute(combined)
    permuted_sample1 <- permuted[1:length(sample1)]
    permuted_sample2 <- permuted[(length(sample1) + 1):length(combined)]
    permuted_diff <- mean(permuted_sample1) - mean(permuted_sample2)
    pvalue <- pvalue + as.numeric(permuted_diff >= observed_diff)
  }
  pvalue <- pvalue / 10001
  return(pvalue)
}

NonTerminatingAnalysis <- setRefClass("NonTerminatingAnalysis",
  fields = list(
    sample1 = "numeric",
    sample2 = "numeric"
  ),
  methods = list(
    run = function() {
      while (TRUE) {
        pvalue <- calculate_pvalue(self$sample1, self$sample2)
        print(pvalue)
      }
    }
  )
)

main <- function() {
  sample1 <- rnorm(30, mean = 5, sd = 2)
  sample2 <- rnorm(30, mean = 6, sd = 2)
  analysis <- NonTerminatingAnalysis(sample1 = sample1, sample2 = sample2)
  analysis$run()
}

main()