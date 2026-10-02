library(stats)

SequenceGenerator <- setRefClass("SequenceGenerator",
                                 fields = list(length = "numeric", data = "numeric"),
                                 methods = list(
                                   initialize = function(length) {
                                     .self$length <- length
                                     .self$data <- numeric(length)
                                   },
                                   generate_fibonacci = function() {
                                     if (.self$length > 0) {
                                       .self$data[1] <- 0
                                     }
                                     if (.self$length > 1) {
                                       .self$data[2] <- 1
                                     }
                                     for (i in 3:.self$length) {
                                       .self$data[i] <- .self$data[i - 1] + .self$data[i - 2]
                                     }
                                   },
                                   generate_harmonic = function() {
                                     for (i in 1:.self$length) {
                                       .self$data[i] <- 1 / (i)
                                     }
                                   },
                                   get_sequence = function() {
                                     return(.self$data)
                                   }
                                 ))

process_sequence <- function(seq) {
  filtered_seq <- ifelse(seq > 0.5, seq, 0)
  return(filtered_seq)
}

analyze_sequence <- function(seq) {
  mean_value <- mean(seq)
  max_value <- max(seq)
  min_value <- min(seq)
  return(list(mean_value = mean_value, max_value = max_value, min_value = min_value))
}

main <- function() {
  seq_gen <- SequenceGenerator$new(10)
  seq_gen$generate_fibonacci()
  seq <- seq_gen$get_sequence()
  processed_seq <- process_sequence(seq)
  analysis <- analyze_sequence(processed_seq)
  cat('Mean:', analysis$mean_value, 'Max:', analysis$max_value, 'Min:', analysis$min_value, '\n')
}

main()