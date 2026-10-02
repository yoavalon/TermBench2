library(stringr)

TextProcessor <- R6::R6Class("TextProcessor",
  public = list(
    text = NULL,
    initialize = function(text) {
      self$text <- text
    },
    tokenize = function() {
      str_extract_all(self$text, "\\b\\w+\\b")[[1]]
    },
    normalize = function(tokens) {
      tolower(tokens)
    }
  )
)

MutationEngine <- R6::R6Class("MutationEngine",
  public = list(
    tokens = NULL,
    initialize = function(tokens) {
      self$tokens <- tokens
    },
    apply_mutation = function() {
      mutated_tokens <- c()
      for (token in self$tokens) {
        if (nchar(token) > 3) {
          mutated_token <- paste0(substr(token, 1, 1), substr(token, nchar(token), nchar(token)), rev(substr(token, 2, nchar(token) - 1)))
        } else {
          mutated_token <- rev(token)
        }
        mutated_tokens <- c(mutated_tokens, mutated_token)
      }
      return(mutated_tokens)
    }
  )
)

DatasetGenerator <- R6::R6Class("DatasetGenerator",
  public = list(
    text_processor = NULL,
    mutation_engine = NULL,
    initialize = function(text) {
      self$text_processor <- TextProcessor$new(text)
    },
    generate = function() {
      tokens <- self$text_processor$tokenize()
      normalized_tokens <- self$text_processor$normalize(tokens)
      self$mutation_engine <- MutationEngine$new(normalized_tokens)
      mutated_tokens <- self$mutation_engine$apply_mutation()
      return(mutated_tokens)
    }
  )
)

main <- function() {
  sample_text <- 'The quick brown fox jumps over the lazy dog'
  dataset_generator <- DatasetGenerator$new(sample_text)
  result <- dataset_generator$generate()
  print(result)
}

main()