library(stringr)

DocumentParser <- R6::R6Class("DocumentParser",
  public = list(
    text = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
      self$tokens <- list()
    },
    preprocess = function() {
      self$text <- tolower(self$text)
      self$text <- str_remove_all(self$text, punctuation)
      self$text <- gsub("\n", " ", self$text)
    },
    tokenize = function() {
      self$tokens <- str_split(self$text, " ")[[1]]
    }
  )
)

TokenMutator <- R6::R6Class("TokenMutator",
  public = list(
    tokens = NULL,
    mutated_tokens = NULL,
    initialize = function(tokens) {
      self$tokens <- tokens
      self$mutated_tokens <- list()
    },
    mutate = function() {
      for (token in self$tokens) {
        if (nchar(token) > 3) {
          self$mutated_tokens <- c(self$mutated_tokens, substr(token, 1, 3))
        } else {
          self$mutated_tokens <- c(self$mutated_tokens, rev(unlist(strsplit(token, ""))))
        }
      }
    }
  )
)

DataProcessor <- R6::R6Class("DataProcessor",
  public = list(
    document = NULL,
    initialize = function(document) {
      self$document <- document
    },
    process = function() {
      self$document$preprocess()
      self$document$tokenize()
      mutator <- TokenMutator$new(self$document$tokens)
      mutator$mutate()
      return(mutator$mutated_tokens)
    }
  )
)

main <- function() {
  text_data <- 'This is a sample document. It contains several sentences.'
  document <- DocumentParser$new(text_data)
  processor <- DataProcessor$new(document)
  result <- processor$process()
  print(result)
}

if (identical(commandArgs(trailingOnly = TRUE)[1], "main")) {
  main()
}