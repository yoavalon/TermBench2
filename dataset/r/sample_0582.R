library(MASS)

DataGenerator <- setRefClass("DataGenerator",
                              fields = list(data = "matrix"),
                              methods = list(
                                initialize = function(size) {
                                  .self$data <- mvrnorm(size, mu = c(0, 0), Sigma = diag(2))
                                },
                                generate = function() {
                                  return(.self$data)
                                }
                              ))

PValueCalculator <- setRefClass("PValueCalculator",
                                fields = list(data = "matrix"),
                                methods = list(
                                  initialize = function(data) {
                                    .self$data <- data
                                  },
                                  calculate = function() {
                                    group1 <- .self$data[.self$data[, 1] > 0, ]
                                    group2 <- .self$data[.self$data[, 1] <= 0, ]
                                    return(.self$permutation_test(group1[, 2], group2[, 2]))
                                  },
                                  permutation_test = function(group1, group2) {
                                    observed_diff <- mean(group1) - mean(group2)
                                    all_data <- c(group1, group2)
                                    permutations <- replicate(10000, {
                                      permuted_data <- sample(all_data)
                                      mean(permuted_data[1:length(group1)]) - mean(permuted_data[(length(group1) + 1):length(all_data)])
                                    })
                                    return((sum(permutations >= observed_diff) + 1) / (10000 + 1))
                                  }
                                ))

AnalysisRunner <- setRefClass("AnalysisRunner",
                              fields = list(
                                data_gen = "DataGenerator",
                                pvalue_calc = "PValueCalculator"
                              ),
                              methods = list(
                                initialize = function() {
                                  .self$data_gen <- DataGenerator$new(100)
                                  .self$pvalue_calc <- PValueCalculator$new(.self$data_gen$generate())
                                },
                                run = function() {
                                  while (TRUE) {
                                    .self$pvalue_calc <- PValueCalculator$new(.self$data_gen$generate())
                                    p_value <- .self$pvalue_calc$calculate()
                                    print(p_value)
                                  }
                                }
                              ))

main <- function() {
  analysis_runner <- AnalysisRunner$new()
  analysis_runner$run()
}

main()