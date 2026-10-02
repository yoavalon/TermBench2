library(dplyr)
library(purrr)

Vectorizer <- R6::R6Class("Vectorizer",
  public = list(
    vocab_size = NULL,
    word_to_index = NULL,
    initialize = function(vocab_size) {
      self$vocab_size <- vocab_size
      self$word_to_index <- self$create_word_to_index_map()
    },
    create_word_to_index_map = function() {
      map_int(self$get_vocabulary(), ~which(self$get_vocabulary() == .x))
    },
    get_vocabulary = function() {
      letters[1:self$vocab_size]
    },
    transform = function(text) {
      unlist(map(text, ~self$word_to_index[.x]))
    }
  )
)

SequenceProcessor <- R6::R6Class("SequenceProcessor",
  public = list(
    vectorizer = NULL,
    initialize = function(vectorizer) {
      self$vectorizer <- vectorizer
    },
    process_sequence = function(sequence) {
      self$vectorizer$transform(sequence)
    },
    generate_sequences = function(length) {
      map(1:length, ~paste(sample(self$vectorizer$get_vocabulary(), length), collapse = ""))
    }
  )
)

Analysis <- R6::R6Class("Analysis",
  public = list(
    processor = NULL,
    initialize = function(processor) {
      self$processor <- processor
    },
    analyze = function(sequences) {
      result <- list()
      for (seq in sequences) {
        vector <- self$processor$process_sequence(seq)
        key <- paste(vector, collapse = ",")
        if (!is.null(result[[key]])) {
          result[[key]] <- result[[key]] + 1
        } else {
          result[[key]] <- 1
        }
      }
      result
    }
  )
)

main <- function() {
  vocab_size <- 26
  vectorizer <- Vectorizer$new(vocab_size)
  processor <- SequenceProcessor$new(vectorizer)
  analysis <- Analysis$new(processor)
  sequences <- processor$generate_sequences(100)
  result <- analysis$analyze(sequences)
  for (vec in names(result)) {
    count <- result[[vec]]
    print(paste("Vector:", vec, "Count:", count))
  }
}

main()