library(boot)

SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    size = NULL,
    data = NULL,
    initialize = function(size) {
      self$size <- size
      self$data <- runif(size)
    },
    generate_sequence = function() {
      return(self$data)
    }
  )
)

PValueCalculator <- R6::R6Class("PValueCalculator",
  public = list(
    sequence1 = NULL,
    sequence2 = NULL,
    initialize = function(sequence1, sequence2) {
      self$sequence1 <- sequence1
      self$sequence2 <- sequence2
    },
    calculate_p_value = function() {
      diff <- mean(self$sequence1) - mean(self$sequence2)
      bootstrap_samples <- replicate(1000, {
        combined <- c(self$sequence1, self$sequence2)
        sample(combined, length(combined), replace = FALSE)
        new_mean_diff <- mean(combined[1:length(self$sequence1)]) - mean(combined[(length(self$sequence1) + 1):length(combined)])
        return(new_mean_diff)
      })
      p_value <- (sum(abs(bootstrap_samples) >= abs(diff)) + 1) / (length(bootstrap_samples) + 1)
      return(p_value)
    }
  )
)

AnalysisRunner <- R6::R6Class("AnalysisRunner",
  public = list(
    sequence_generator1 = NULL,
    sequence_generator2 = NULL,
    initialize = function(sequence_generator1, sequence_generator2) {
      self$sequence_generator1 <- sequence_generator1
      self$sequence_generator2 <- sequence_generator2
    },
    run_analysis = function() {
      seq1 <- self$sequence_generator1$generate_sequence()
      seq2 <- self$sequence_generator2$generate_sequence()
      p_value_calculator <- PValueCalculator$new(seq1, seq2)
      p_value <- p_value_calculator$calculate_p_value()
      return(p_value)
    }
  )
)

main <- function() {
  size1 <- 100
  size2 <- 100
  seq_gen1 <- SequenceGenerator$new(size1)
  seq_gen2 <- SequenceGenerator$new(size2)
  analysis_runner <- AnalysisRunner$new(seq_gen1, seq_gen2)
  result <- analysis_runner$run_analysis()
  print(result)
}

main()