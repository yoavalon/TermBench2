library(stats)

PValuePermutations <- setRefClass("PValuePermutations",
  fields = list(data1 = "numeric", data2 = "numeric", mean_diff = "numeric", permuted_diffs = "numeric"),
  methods = list(
    initialize = function(data1, data2) {
      .self$data1 <- data1
      .self$data2 <- data2
      .self$mean_diff <- .self$calculate_mean_difference(data1, data2)
      .self$permuted_diffs <- c()
    },
    calculate_mean_difference = function(a, b) {
      abs(mean(a) - mean(b))
    },
    permute_and_compare = function(count) {
      if (count > 0) {
        combined_data <- c(.self$data1, .self$data2)
        permuted_data1 <- sample(combined_data, length(.self$data1))
        permuted_data2 <- combined_data[!(combined_data %in% permuted_data1)]
        permuted_diff <- .self$calculate_mean_difference(permuted_data1, permuted_data2)
        .self$permuted_diffs <- c(.self$permuted_diffs, permuted_diff)
        .self$permute_and_compare(count - 1)
      }
    },
    calculate_p_value = function() {
      sum(.self$permuted_diffs >= .self$mean_diff) / length(.self$permuted_diffs)
    }
  )
)

AnalysisRunner <- setRefClass("AnalysisRunner",
  fields = list(p_value_calculator = "PValuePermutations"),
  methods = list(
    initialize = function(data1, data2) {
      .self$p_value_calculator <- PValuePermutations$new(data1, data2)
    },
    run_analysis = function(permutation_count) {
      .self$p_value_calculator$permute_and_compare(permutation_count)
      .self$p_value_calculator$calculate_p_value()
    }
  )
)

main <- function() {
  data1 <- rnorm(100, 0, 1)
  data2 <- rnorm(100, 0.5, 1)
  analysis_runner <- AnalysisRunner$new(data1, data2)
  while (TRUE) {
    p_value <- analysis_runner$run_analysis(1000)
    cat('P-value:', p_value, '\n')
  }
}

main()