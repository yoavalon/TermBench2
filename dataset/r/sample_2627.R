library(stringr)

TextProcessor <- R6::R6Class("TextProcessor",
  public = list(
    text = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
      self$tokens <- list()
    },
    tokenize = function() {
      self$tokens <- str_extract_all(tolower(self$text), '\\b\\w+\\b')[[1]]
    }
  )
)

SequenceAnalyzer <- R6::R6Class("SequenceAnalyzer",
  public = list(
    tokens = NULL,
    sequences = NULL,
    initialize = function(tokens) {
      self$tokens <- tokens
      self$sequences <- list()
    },
    identify_sequences = function() {
      for (i in 1:(length(self$tokens) - 1)) {
        pair <- paste(self$tokens[i], self$tokens[i + 1], sep = " ")
        if (pair %in% names(self$sequences)) {
          self$sequences[[pair]] <- self$sequences[[pair]] + 1
        } else {
          self$sequences[[pair]] <- 1
        }
      }
    }
  )
)

ReportGenerator <- R6::R6Class("ReportGenerator",
  public = list(
    sequences = NULL,
    initialize = function(sequences) {
      self$sequences <- sequences
    },
    generate_report = function() {
      report <- sort(self$sequences, decreasing = TRUE)
      return(report)
    }
  )
)

main <- function() {
  text <- 'This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.'
  processor <- TextProcessor$new(text)
  processor$tokenize()
  analyzer <- SequenceAnalyzer$new(processor$tokens)
  analyzer$identify_sequences()
  generator <- ReportGenerator$new(analyzer$sequences)
  report <- generator$generate_report()
  for (i in 1:10) {
    sequence <- names(report)[i]
    count <- report[i]
    cat(sprintf('Sequence: %s, Count: %s\n', sequence, count))
  }
}

main()